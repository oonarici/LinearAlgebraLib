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