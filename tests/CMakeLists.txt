# tests/CMakeLists.txt

find_package(GTest REQUIRED)

add_executable(LinearAlgebraTests
        VectorTest.cpp
        MatrixTest.cpp
        ${CMAKE_SOURCE_DIR}/src/Vector3D.cpp
)

target_link_libraries(LinearAlgebraTests
        PRIVATE
        LinearAlgebraLib   #  .so
        GTest::gtest       # GTest core
        GTest::gtest_main  # InitGoogleTest ve main()
)

include(GoogleTest)
gtest_discover_tests(LinearAlgebraTests)