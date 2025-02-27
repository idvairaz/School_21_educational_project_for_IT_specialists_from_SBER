#include "test.h"

TEST(TestSupporting, 00_MINOR) {
  S21Matrix A(1, 1);
  A.setElement(0, 0, 0.5);

  ASSERT_ANY_THROW(A.getMinor(1, 1));
}

TEST(TestSupporting, 01_MINOR) {
  S21Matrix A(3, 3);

  A.setElement(0, 0, 0.5);
  A.setElement(0, 1, 0.1);
  A.setElement(0, 2, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);
  A.setElement(1, 2, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);
  A.setElement(2, 2, 2.1);

  S21Matrix C(2, 2);
  C = A.getMinor(1, 1);

  /* Матрица B - объект для сравнения после выполнения метода */

  S21Matrix B(2, 2);

  B.setElement(0, 0, 0.5);
  B.setElement(0, 1, 0.1);

  B.setElement(1, 0, 2.0);
  B.setElement(1, 1, 2.1);

  EXPECT_TRUE(B.eqMatrix(C));
}
TEST(TestSupporting, 02_isSquare) {
  S21Matrix A(5, 1);
  EXPECT_TRUE(A.isSquare() == 0);
}
TEST(TestSupporting, 03_MINOR) {
  S21Matrix A(1, 1);
  A.setElement(0, 0, 0.5);

  ASSERT_ANY_THROW(A.getMinor(1, -1));
}

TEST(TestSupporting, 04_setElement) {
  S21Matrix A(1, 1);
  ASSERT_ANY_THROW(A.setElement(0, 1, 0.5));
}
TEST(TestSupporting, 05_operator) {
  S21Matrix A(1, 1);
  A.setElement(0, 0, 0.5);
  ASSERT_ANY_THROW(A(0, 1));
}
TEST(TestSupporting, 06_constructor) { ASSERT_ANY_THROW(S21Matrix A(1, -1)); }

TEST(TestSupporting, 07_sets) {
  S21Matrix A;
  A.setRows(1);
  A.setCols(1);
  ASSERT_TRUE(A.getRows() == 1);
  ASSERT_TRUE(A.getCols() == 1);
}
