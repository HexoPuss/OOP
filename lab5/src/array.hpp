#include <memory_resource>
#include <list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include "custom_memory_resourse.hpp"

template <typename T>
class DynamicArray {
private:
    size_t size_;
    size_t capacity_;
    T* data_;
    std::pmr::polymorphic_allocator<T> allocator_;

    void resize() {
        if (size_ >= capacity_) {
            size_t new_capacity = capacity_ * 2;
            T* new_data = allocator_.allocate(new_capacity);

            for (size_t i = 0; i < size_; ++i) {
                new (new_data + i) T(std::move(data_[i]));
                data_[i].~T();
            }

            allocator_.deallocate(data_, capacity_);
            data_ = new_data;
            capacity_ = new_capacity;
        }
    }

public:
    explicit DynamicArray(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
            : size_(0), capacity_(1), data_(nullptr), allocator_(resource) {
        data_ = allocator_.allocate(capacity_);
    }

    ~DynamicArray() {
        for (size_t i = 0; i < size_; ++i) {
            data_[i].~T();
        }
        allocator_.deallocate(data_, capacity_);
    }

    void push_back(const T& value) {
        resize();
        new (data_ + size_) T(value);
        ++size_;
    }

    void push_back(T&& value) {
        resize();
        new (data_ + size_) T(std::move(value));
        ++size_;
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    size_t size() const { return size_; }

    // Forward iterator
    class Iterator {
    private:
        T* ptr_;

    public:
        explicit Iterator(T* ptr) : ptr_(ptr) {}

        T& operator*() const { return *ptr_; }
        Iterator& operator++() {
            ++ptr_;
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr_;
            return temp;
        }
        bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const Iterator& other) const { return ptr_ != other.ptr_; }
    };

    Iterator begin() { return Iterator(data_); }
    Iterator end() { return Iterator(data_ + size_); }
};