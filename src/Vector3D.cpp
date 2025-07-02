#include "LinearAlgebraLib/Vector3D.hpp"
#include <algorithm>    // std::copy
#include <stdexcept>    // std::invalid_argument

namespace lalib {

    template<typename T>
    Vector3D<T>::Vector3D() : m_data{T{}, T{}, T{}} {
    }

    template<typename T>
    Vector3D<T>::Vector3D(T x, T y, T z) {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    template<typename T>
    Vector3D<T>::Vector3D(std::initializer_list<T> init) {

        if (static_cast<int>(init.size()) != 3) {

            throw std::invalid_argument("Vector must be initialized with 3 elements.");
        }
        std::copy(init.begin(), init.end(), m_data.begin());
    }

    template<typename T>
    T& Vector3D<T>::operator[](std::size_t index){

        if (index >= m_data.size()) {

            throw std::out_of_range("Vector index out of bounds.");
        }
        return m_data[index];
    }

    template<typename T>
    const T& Vector3D<T>::operator[](std::size_t index) const {

        if (index >= m_data.size()) {

            throw std::out_of_range("Vector index out of bounds.");
        }
        return m_data.at(index);
    }

    template<typename T>
    const T & Vector3D<T>::x() const {

        return m_data[0];
    }

    template<typename T>
    const T &Vector3D<T>::y() const {

        return m_data[1];
    }

    template<typename T>
    const T &Vector3D<T>::z() const {

        return m_data[2];
    }

    template<typename T>
    Vector3D<T> Vector3D<T>::operator+(const Vector3D &other) const {

        return {m_data[0] + other[0], m_data[1] + other[1], m_data[2] + other[2]};
    }

    template<typename T>
    Vector3D<T> Vector3D<T>::operator-(const Vector3D& other) const {
        return {m_data[0] - other[0], m_data[1] - other[1], m_data[2] - other[2]};
    }

    template<typename T>
    Vector3D<T> Vector3D<T>::operator*(const T& other) const {
        return {m_data[0] * other, m_data[1] * other, m_data[2] * other};
    }

    template<typename T>
    T Vector3D<T>::dot(const Vector3D& o) const {

        return m_data[0] * o[0] +
               m_data[1] * o[1] +
               m_data[2] * o[2];
    }

    template<typename T>
    Vector3D<T> Vector3D<T>::cross(const Vector3D &other) const {

        Vector3D<T> result_vector;
        result_vector[0] = m_data[1] * other[2] - m_data[2] * other[1];
        result_vector[1] = m_data[2] * other[0] - m_data[0] * other[2];
        result_vector[2] = m_data[0] * other[1] - m_data[1] * other[0];

        return result_vector;
    }

    template<typename T>
    bool Vector3D<T>::operator==(const Vector3D &o) const {

        return m_data == o.m_data;
    }
} // namespace lalib
