//
// Created by onur onarici 03.06.2025.
//

#include <gtest/gtest.h>
#include "LinearAlgebraLib/Vector3D.hpp"

using lalib::Vector3D;

TEST(VectorTest, ConstructorAndAccess) {

    Vector3D<int> v(1, 2, 3);
    EXPECT_EQ(v.x(), 1);
    EXPECT_EQ(v.y(), 2);
    EXPECT_EQ(v.z(), 3);

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, ThrowException) {

    Vector3D<int> v(1, 2, 3);
    EXPECT_THROW(v[3], std::out_of_range);
    EXPECT_THROW(v[34], std::out_of_range);
}

TEST(VectorTest, Summation) {

    Vector3D<int> v1(1, 2, 3);
    Vector3D<int> v2(9, 8, 7);

    Vector3D<int> v3 = v1 + v2;
    EXPECT_EQ(v3.x(), 10);
    EXPECT_EQ(v3.y(), 10);
    EXPECT_EQ(v3.z(), 10);
}

TEST(VectorTest, Substraction) {

    Vector3D<int> v1(1, 2, 3);
    Vector3D<int> v2(9, 8, 7);

    Vector3D<int> v3 = v2 - v1;
    EXPECT_EQ(v3.x(), 8);
    EXPECT_EQ(v3.y(), 6);
    EXPECT_EQ(v3.z(), 4);
}

TEST(VectorTest, MultiplyByScalar) {

    Vector3D<int> v1(1, 2, 3);
    int x = 3;

    Vector3D<int> v3 = v1 * x;
    EXPECT_EQ(v3.x(), 3);
    EXPECT_EQ(v3.y(), 6);
    EXPECT_EQ(v3.z(), 9);
}

TEST(VectorTest, DotProduct) {

    Vector3D<int> v1(1, 2, 3);
    Vector3D<int> v2(9, 8, 7);

    int x = v1.dot(v2);
    EXPECT_EQ(x, 46);
}

TEST(VectorTest, Cross_Product) {

    Vector3D<int> v1(1, 2, 3);
    Vector3D<int> v2(3, 4, 5);

    Vector3D v3 = v1.cross(v2);
    EXPECT_EQ(v3.x(), -2);
    EXPECT_EQ(v3.y(), 4);
    EXPECT_EQ(v3.z(), -2);
}