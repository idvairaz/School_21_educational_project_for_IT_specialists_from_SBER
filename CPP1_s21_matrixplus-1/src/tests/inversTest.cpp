#include "test.h"

TEST(TestInvers, 00_invers0) {
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
  result = mat.inverseMatrix();

  S21Matrix expected(4, 4);

  expected.setElement(0, 0, 0);
  expected.setElement(0, 1, 1);
  expected.setElement(0, 2, 0);
  expected.setElement(0, 3, 0);

  expected.setElement(1, 0, -5.0 / 23.0);
  expected.setElement(1, 1, -121.0 / 23.0);
  expected.setElement(1, 2, 2.0 / 23.0);
  expected.setElement(1, 3, 1.0 / 23.0);

  expected.setElement(2, 0, -18.0 / 23.0);
  expected.setElement(2, 1, -379.0 / 46.0);
  expected.setElement(2, 2, 19.0 / 46.0);
  expected.setElement(2, 3, -25.0 / 46.0);

  expected.setElement(3, 0, 53.0 / 69.0);
  expected.setElement(3, 1, 1061.0 / 138.0);
  expected.setElement(3, 2, -47.0 / 138.0);
  expected.setElement(3, 3, 19.0 / 46.0);

  EXPECT_TRUE(result == expected);
}

TEST(TestInvers, 01_invers1) {
  S21Matrix mat(3, 4);

  S21Matrix result(4, 4);

  EXPECT_ANY_THROW(result = mat.inverseMatrix());
}
TEST(TestInvers, 02_invers2) {
  S21Matrix mat(3, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 4);
  mat.setElement(1, 1, 5);
  mat.setElement(1, 2, 6);

  mat.setElement(2, 0, 7);
  mat.setElement(2, 1, 8);
  mat.setElement(2, 2, 9);

  S21Matrix result(3, 3);
  EXPECT_ANY_THROW(result = mat.inverseMatrix());
}

TEST(TestInvers, 03_invers3) {
  S21Matrix mat(2, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 4);
  mat.setElement(1, 2, 2);

  S21Matrix result(2, 3);

  EXPECT_ANY_THROW(result = mat.inverseMatrix());
}
