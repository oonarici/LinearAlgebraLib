# tests/CMakeLists.txt

find_package(GTest REQUIRED)

add_executable(
        LinearAlgebraTests
        VectorTest.cpp
)

target_link_libraries(LinearAlgebraTests PRIVATE
        LinearAlgebraLib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LinearAlgebraTests)