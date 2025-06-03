#pragma once
#include <array>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>

namespace lalib {

    template<typename T>
    class Vector {
    public:
        Vector();
        Vector(T x, T y, T z);
        Vector(std::initializer_list<T> init);

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        T& x();  T& y();  T& z();
        const T& x() const;  const T& y() const;  const T& z() const;

        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(T scalar) const;
        T dot(const Vector& other) const;

        bool operator==(const Vector& other) const;
        bool operator!=(const Vector& other) const;

    private:
        std::array<T, 3> m_data;
    };

} // namespace lalib
