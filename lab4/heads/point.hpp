
    #include <iostream>
    #include <type_traits>
    #include <concepts>
    #include <utility>
    #include <memory>

    #ifndef POINT
    #define POINT

    template <typename T>
    concept coordinate = std::is_integral_v<T> || std::is_floating_point_v<T>;

    template <coordinate T>
    class Point final
    {
    public:
        T x;
        T y;


        Point() noexcept : x{}, y{} {}
        Point(T x, T y) noexcept : x{x}, y{y} {}
        Point(const Point<T> &other) noexcept : x{other.x}, y{other.y} {}
        Point<T> &operator=(const Point<T> &other) noexcept
        {
            if (&other != this)
            {
                this->x = other.x;
                this->y = other.y;
            }
            return *this;
        }
        Point(Point<T> &&other) noexcept : x{std::move(other.x)}, y{std::move(other.y)} {}
        Point<T> &operator=(Point<T> &&other) noexcept
        {
            if (&other != this)
            {
                this->x = std::move(other.x);
                this->y = std::move(other.y);
            }
            return *this;
        }
        ~Point() noexcept {}
        bool operator==(const Point<T> &other) const noexcept { return this->x == other.x and this->y == other.y; }
        bool operator!=(const Point<T> &other) const noexcept { return this->x != other.x or this->y != other.y; }
        T X() const noexcept { return x; }
        T Y() const noexcept { return y; }
        void setX(T x) noexcept { this->x = x; }
        void setY(T y) noexcept { this->y = y; }
        friend std::istream &operator>>(std::istream &stream, Point<T> &object) { return object.read(stream); }
        friend std::ostream &operator<<(std::ostream &stream, const Point<T> &object) { return object.write(stream); }

    private:
        std::istream &read(std::istream &stream) { 
            stream >> x;
            stream >> y;            
            return stream;
        }
        std::ostream &write(std::ostream &stream) const { return stream << "(" << x << " ; " << y << ")"; }
    };


    #endif