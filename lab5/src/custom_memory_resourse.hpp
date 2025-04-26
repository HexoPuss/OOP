#pragma once
#include <iostream>
#include <memory_resource>
#include <map>
#include <cstddef>
#include <new>
#include <cassert>

struct BlockInfo {
    size_t Size;
    bool IsFree;
    size_t alignment;
};

class CustomMemoryResource : public std::pmr::memory_resource {
private:
    std::map<void*, BlockInfo> blocks;

protected:
    void* do_allocate(size_t bytes, size_t alignment) override {
        for (auto& [ptr, info] : blocks) {
            if (info.IsFree && info.Size >= bytes &&
                info.alignment == alignment) {
                info.IsFree = false;
                return ptr;
            }
        }
        void* ptr = ::operator new(bytes, std::align_val_t(alignment) );
        blocks[ptr] = {bytes, false, alignment};
        return ptr;
    }

    void do_deallocate(void* ptr, size_t bytes, size_t alignment ) override {
        (void)alignment;
        auto it = blocks.find(ptr);
        if (it != blocks.end()) {
            assert(it->second.Size >= bytes);
            it->second.IsFree = true;
        } else {
            std::cerr << "ошибка: неизвестный указатель !\n";
        }
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

public:
public:
    ~CustomMemoryResource() {
        for (auto& [ptr, info] : blocks) {
            ::operator delete(ptr, std::align_val_t(info.alignment));
        }
    }
};
