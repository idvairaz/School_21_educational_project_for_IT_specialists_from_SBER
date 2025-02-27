#include "test.h"

TEST(TestCalc, 00_calc0) {
  S21Matrix mat(4, 4);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);
  mat.setElement(0, 3, 3);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 4);
  mat.setElement(1, 2, 2);
  mat.setElement(1, 3, 2);

  mat.setElement(2, 0, 5);
  mat.setElement(2, 1, 2);
  mat.setElement(2, 2, 1);
  mat.setElement(2, 3, 1);

  mat.setElement(3, 0, 5);
  mat.setElement(3, 1, 2);
  mat.setElement(3, 2, 5);
  mat.setElement(3, 3, 1);

  S21Matrix result(4, 4);
  result = mat.calcComplements();

  S21Matrix expected(4, 4);

  expected.setElement(0, 0, 0);
  expected.setElement(0, 1, -40);
  expected.setElement(0, 2, 0);
  expected.setElement(0, 3, 80);

  expected.setElement(1, 0, -16);
  expected.setElement(1, 1, 56);
  expected.setElement(1, 2, 0);
  expected.setElement(1, 3, -32);

  expected.setElement(2, 0, 32);
  expected.setElement(2, 1, 8);
  expected.setElement(2, 2, -40);
  expected.setElement(2, 3, 24);

  expected.setElement(3, 0, 0);
  expected.setElement(3, 1, 0);
  expected.setElement(3, 2, 40);
  expected.setElement(3, 3, -40);

  EXPECT_TRUE(result == expected);
}

TEST(TestCalc, 01_calc1) {
  S21Matrix mat(4, 4);
  mat.setElement(0, 0, -1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 7);
  mat.setElement(0, 3, 9);

  mat.setElement(1, 0, 1);
  mat.setElement(1, 1, 0);
  mat.setElement(1, 2, 0);
  mat.setElement(1, 3, 0);

  mat.setElement(2, 0, 47);
  mat.setElement(2, 1, 13);
  mat.setElement(2, 2, 17);
  mat.setElement(2, 3, 21);

  mat.setElement(3, 0, 22);
  mat.setElement(3, 1, 7);
  mat.setElement(3, 2, 1);
  mat.setElement(3, 3, 3);

  S21Matrix result(4, 4);
  result = mat.calcComplements();

  S21Matrix expected(4, 4);

  expected.setElement(0, 0, 0);
  expected.setElement(0, 1, -30);
  expected.setElement(0, 2, -108);
  expected.setElement(0, 3, 106);

  expected.setElement(1, 0, 138);
  expected.setElement(1, 1, -726);
  expected.setElement(1, 2, -1137);
  expected.setElement(1, 3, 1061);

  expected.setElement(2, 0, 0);
  expected.setElement(2, 1, 12);
  expected.setElement(2, 2, 57);
  expected.setElement(2, 3, -47);

  expected.setElement(3, 0, 0);
  expected.setElement(3, 1, 6);
  expected.setElement(3, 2, -75);
  expected.setElement(3, 3, 57);

  EXPECT_TRUE(result == expected);
}
TEST(TestCalc, 02_calc2) {
  S21Matrix mat(3, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 4);
  mat.setElement(1, 2, 2);

  mat.setElement(2, 0, 5);
  mat.setElement(2, 1, 2);
  mat.setElement(2, 2, 1);

  S21Matrix result(3, 3);
  result = mat.calcComplements();

  S21Matrix expected(3, 3);

  expected.setElement(0, 0, 0);
  expected.setElement(0, 1, 10);
  expected.setElement(0, 2, -20);

  expected.setElement(1, 0, 4);
  expected.setElement(1, 1, -14);
  expected.setElement(1, 2, 8);

  expected.setElement(2, 0, -8);
  expected.setElement(2, 1, -2);
  expected.setElement(2, 2, 4);

  EXPECT_TRUE(result == expected);
}

TEST(TestCalc, 03_calc3) {
  S21Matrix mat(2, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 4);
  mat.setElement(1, 2, 2);

  S21Matrix result(2, 3);

  EXPECT_ANY_THROW(result = mat.calcComplements());
}

TEST(TestCalc, 04_calc4) {
  S21Matrix mat(2, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 4);
  mat.setElement(1, 2, 2);

  S21Matrix result(3, 3);

  EXPECT_ANY_THROW(result = mat.calcComplements());
}
