#include "LinearAlgebraLib/Vector3D.hpp"
#include <algorithm>    // std::copy
#include <stdexcept>    // std::invalid_argument

namespace lalib {
    template<typename T>
    Vector3D<T>::Vector3D() : m_data{T{}, T{}, T{}} {
    }

    template<typename T>
    Vector3D<T>::Vector3D(std::initializer_list<T> init) {
        if (init.size() != 3)
            throw std::invalid_argument("Vector must be initialized with 3 elements.");
        std::copy(init.begin(), init.end(), m_data.begin());
    }

    template<typename T>
    T &Vector3D<T>::operator[](std::size_t index) {
        return m_data[index];
    }

    template<typename T>
    const T &Vector3D<T>::operator[](std::size_t index) const {
        return m_data[index];
    }

    template<typename T>
    T &Vector3D<T>::x() { return m_data[0]; }

    template<typename T>
    T &Vector3D<T>::y() { return m_data[1]; }

    template<typename T>
    T &Vector3D<T>::z() { return m_data[2]; }

    template<typename T>
    const T &Vector3D<T>::x() const { return m_data[0]; }

    template<typename T>
    const T &Vector3D<T>::y() const { return m_data[1]; }

    template<typename T>
    const T &Vector3D<T>::z() const { return m_data[2]; }

    template<>
    Vector<int> Vector<int>::operator+(const Vector &o) const {

        return {m_data[0] + o[0], m_data[1] + o[1], m_data[2] + o[2]};
    }

    template<>
    Vector<float> Vector<float>::operator+(const Vector &o) const {

        return {m_data[0] + o[0], m_data[1] + o[1], m_data[2] + o[2]};
    }

    template<>
    Vector<double> Vector<double>::operator+(const Vector &o) const {

        return {m_data[0] + o[0], m_data[1] + o[1], m_data[2] + o[2]};
    }

    template<typename T>
    Vector3D<T> Vector3D<T>::operator-(const Vector3D &o) const {
        return {m_data[0] - o[0], m_data[1] - o[1], m_data[2] - o[2]};
    }

    template<typename T>
    Vector3D<T> Vector3D<T>::operator*(T s) const {
        return {m_data[0] * s, m_data[1] * s, m_data[2] * s};
    }

    template<typename T>
    T Vector3D<T>::dot(const Vector3D &o) const {
        return m_data[0] * o[0]
               + m_data[1] * o[1]
               + m_data[2] * o[2];
    }

    template<typename T>
    bool Vector3D<T>::operator==(const Vector3D &o) const {
        return m_data == o.m_data;
    }

    template<typename T>
    bool Vector3D<T>::operator!=(const Vector3D &o) const {
        return !(*this == o);
    }

    template class Vector3D<int>;
    template class Vector3D<float>;
} // namespace lalib
