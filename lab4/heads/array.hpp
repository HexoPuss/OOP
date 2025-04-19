#pragma once

#include <type_traits>
#include <concepts>
#include <stdexcept>
#include <limits>
#include <utility>
#include <cstddef>
#include <memory>

template <class T>
concept arrayElement = std::is_default_constructible_v<T> &&
                       (std::is_copy_constructible_v<T> || std::is_move_constructible_v<T>) &&
                       (std::is_copy_assignable_v<T> || std::is_move_assignable_v<T>) &&
                       std::is_nothrow_destructible_v<T>;

constexpr const size_t initialSize{1};

template <arrayElement T>
class Array final
{
public:
    Array() : _poolSize{initialSize}, _currentSize{}, _array{std::make_unique<T[]>(initialSize)} {}

    Array(size_t initialSize) : _poolSize{initialSize}, _currentSize{}, _array{std::make_unique<T[]>(initialSize)} {}

    Array(const Array<T> &other) : _poolSize{other._poolSize}, _currentSize{other._currentSize}, _array{std::make_unique<T[]>(other._poolSize)}
    {
        try
        {
            for (size_t i{}; i < _currentSize; ++i)
                _array.get()[i] = other._array.get()[i];
        }
        catch (...)
        {
            _array.reset();
            throw;
        }
    }

    Array<T> &operator=(const Array<T> &other)
    {
        if (&other != this)
        {
            std::unique_ptr<T[]> newArray = nullptr;
            try
            {
                newArray = std::make_unique<T[]>(other._poolSize);
                for (size_t i{}; i < other._currentSize; ++i)
                    newArray.get()[i] = other._array.get()[i];
            }
            catch (...)
            {
                newArray.reset();
                throw;
            }
            _array.reset();
            _array = std::move(newArray);
            _poolSize = other._poolSize;
            _currentSize = other._currentSize;
        }
        return *this;
    }

    Array(Array<T> &&other) noexcept : _poolSize{other._poolSize}, _currentSize{other._currentSize}, _array{std::move(other._array)}
    {
        other._poolSize = 0;
        other._currentSize = 0;
        other._array = nullptr;
    }

    Array<T> &operator=(Array<T> &&other) noexcept
    {
        if (&other != this)
        {
            _array.reset();
            _array = std::move(other._array);
            _poolSize = other._poolSize;
            _currentSize = other._currentSize;

            other._poolSize = 0;
            other._currentSize = 0;
            other._array = nullptr;
        }
        return *this;
    }

    ~Array() noexcept
    {
        _currentSize = 0;
        _poolSize = 0;
        _array.reset();
    }

    size_t getSize() const noexcept
    {
        return _currentSize;
    }

    T &operator[](size_t index)
    {
        if (index < _currentSize && index >= 0)
            return _array.get()[index];
        else
            throw std::out_of_range("Ошибка: выход за границы массива.");
    }

    const T &operator[](size_t index) const
    {
        if (index < _currentSize)
            return _array.get()[index];
        else
            throw std::out_of_range("Ошибка: выход за границы массива.");
    }

    void pushBack(const T &value)
    {
        if (_currentSize < _poolSize)
        {
            _array.get()[_currentSize] = value;
            ++_currentSize;
        }
        else
            try
            {
                if (_poolSize > std::numeric_limits<size_t>::max() / 2)
                    throw std::overflow_error("Ошибка: превышение максимального размера массива.");

                try
                {
                    _reallocate(_poolSize * 2);
                }
                catch (...)
                {
                    throw;
                }
                _array.get()[_currentSize] = value;
                ++_currentSize;
            }
            catch (...)
            {
                throw;
            }
    }

    void pushBack(T &&value)
    {
        if (_currentSize < _poolSize)
        {
            _array.get()[_currentSize] = std::move(value);
            ++_currentSize;
        }
        else
            try
            {
                if (_poolSize > std::numeric_limits<size_t>::max() / 2)
                    throw std::overflow_error("Ошибка: превышение максимального размера массива.");

                try
                {
                    _reallocate(_poolSize * 2);
                }
                catch (...)
                {
                    throw;
                }
                _array.get()[_currentSize] = std::move(value);
                ++_currentSize;
            }
            catch (...)
            {
                throw;
            }
    }

    void remove(size_t index)
    {
        if (index < _currentSize)
        {
            size_t newCurrentSize{_currentSize - 1};
            size_t newPoolSize;
            if (newCurrentSize != 0)
                if (_poolSize / newCurrentSize > 2)
                    newPoolSize = _poolSize / 2;
                else
                    newPoolSize = _poolSize;
            else
                newPoolSize = _poolSize;

            std::unique_ptr<T[]> newArray = nullptr;
            try
            {
                newArray = std::make_unique<T[]>(newPoolSize);

                for (size_t i{}; i < index; ++i)
                    newArray.get()[i] = std::move(_array.get()[i]);

                for (size_t i{index}; i < newCurrentSize; ++i)
                    newArray.get()[i] = std::move(_array.get()[i + 1]);
            }
            catch (...)
            {
                newArray.reset();
                throw;
            }

            _array.reset();
            _array = std::move(newArray);
            _poolSize = newPoolSize;
            _currentSize = newCurrentSize;
        }
        else
            throw std::out_of_range("Ошибка: выход за границы массива.");
    }

private:
    size_t _poolSize;
    size_t _currentSize;
    std::unique_ptr<T[]> _array;

    void _reallocate(const size_t &newPoolSize)
    {
        std::unique_ptr<T[]> newArray = nullptr;
        try
        {
            newArray = std::make_unique<T[]>(newPoolSize);
            for (size_t i{}; i < _currentSize; ++i)
                newArray.get()[i] = std::move(_array.get()[i]);
        }
        catch (...)
        {
            newArray.reset();
            throw;
        }
        _array.reset();
        _array = std::move(newArray);
        _poolSize = newPoolSize;
    }
};