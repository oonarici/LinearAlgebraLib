#pragma once
#include <array>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>

namespace lalib {

    template<typename T>
    class Vector3D {
    public:
        Vector3D();
        Vector3D(T x, T y, T z);
        Vector3D(std::initializer_list<T> init);

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        T& x();  T& y();  T& z();
        const T& x() const;
        const T& y() const;
        const T& z() const;

        Vector3D operator+(const Vector3D& other) const;
        Vector3D operator-(const Vector3D& other) const;
        Vector3D operator*(T scalar) const;
        T dot(const Vector3D& other) const;

        bool operator==(const Vector3D& other) const;
        bool operator!=(const Vector3D& other) const;

    private:
        std::array<T, 3> m_data;
    };
} // namespace lalib
