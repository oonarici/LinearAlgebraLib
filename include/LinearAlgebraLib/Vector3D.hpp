#pragma once

#include <array>
#include <initializer_list>
#include <cstddef>

namespace lalib {

    template<typename T>
    class Vector3D {

        std::array<T, 3> m_data;

    public:
        Vector3D();
        Vector3D(T x, T y, T z);
        Vector3D(std::initializer_list<T> init);

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        const T& x() const;
        const T& y() const;
        const T& z() const;

        Vector3D operator+(const Vector3D& other) const;
        Vector3D operator-(const Vector3D& other) const;
        Vector3D<T> operator*(const T& other) const;
        T dot(const Vector3D& other) const;
        Vector3D<T> cross(const Vector3D& other) const;

        bool operator==(const Vector3D& other) const;
    };
    template class lalib::Vector3D<int>;
    template class lalib::Vector3D<float>;
    template class lalib::Vector3D<double>;
} // namespace lalib
