cmake_minimum_required(VERSION 3.27)
project(CPP1_s21_matrixplus_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP1_s21_matrixplus_1
        src/tests/mainTest.cpp
        src/lib/S21Matrix.cpp
        src/S21Matrix.h
        src/tests/eqTest.cpp
        src/tests/sumTest.cpp
        src/tests/test.h
        src/tests/subTest.cpp
        src/tests/mulTest.cpp
        src/tests/transposeTest.cpp
        src/tests/supportAndExeptionTest.cpp
        src/tests/determinantTest.cpp
        src/tests/calcComplementsTest.cpp
        src/tests/inversTest.cpp
        src/lib/operatorsMatrix.cpp
        src/lib/methodsMatrix.cpp
        src/lib/support.cpp)


target_compile_options(CPP1_s21_matrixplus_1 PRIVATE
        -Bstatic
        -Bdynamic
)

# Добавьте библиотеки
target_link_libraries(CPP1_s21_matrixplus_1
        gtest
        gcov
        pthread
        m
)