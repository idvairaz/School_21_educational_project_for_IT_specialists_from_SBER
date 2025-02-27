#include "test.h"

TEST(TestMul, 00_MulNum) {
  double num = 5.5;
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  A.mulNumber(num);

  /* Матрица B - объект для сравнения после выполнения метода */

  S21Matrix B(3, 2);
  B.setElement(0, 0, 0.0123456789 * num);
  B.setElement(0, 1, 0.1 * num);

  B.setElement(1, 0, 1.0 * num);
  B.setElement(1, 1, 1.1 * num);

  B.setElement(2, 0, 2.0 * num);
  B.setElement(2, 1, 2.1 * num);

  EXPECT_TRUE(A.eqMatrix(B));
}

TEST(TestMul, 01_MulEqNumOperator) {
  double num = 0;
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  A *= num;

  /* Матрица B - объект для сравнения после выполнения метода */

  S21Matrix B(3, 2);
  EXPECT_TRUE(B.eqMatrix(A));
}
TEST(TestMul, 02_MulMX) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 1.0);
  A.setElement(0, 1, 4.0);

  A.setElement(1, 0, 2.0);
  A.setElement(1, 1, 5.0);

  A.setElement(2, 0, 3.0);
  A.setElement(2, 1, 6.0);

  S21Matrix B(2, 3);
  B.setElement(0, 0, 1.0);
  B.setElement(0, 1, -1.0);
  B.setElement(0, 2, 1.0);

  B.setElement(1, 0, 2.0);
  B.setElement(1, 1, 3.0);
  B.setElement(1, 2, 4.0);

  A.mulMatrix(B);

  /* Матрица С - объект для сравнения после выполнения метода */

  S21Matrix C(3, 3);

  C.setElement(0, 0, 9.0);
  C.setElement(0, 1, 11.0);
  C.setElement(0, 2, 17.0);

  C.setElement(1, 0, 12.0);
  C.setElement(1, 1, 13.0);
  C.setElement(1, 2, 22.0);

  C.setElement(2, 0, 15.0);
  C.setElement(2, 1, 15.0);
  C.setElement(2, 2, 27.0);

  EXPECT_TRUE(A.eqMatrix(C));
}

TEST(TestMul, 03_MulMXThrow) {
  S21Matrix A(3, 2);
  S21Matrix B(5, 5);

  ASSERT_ANY_THROW(A.mulMatrix(B));
}

TEST(TestMul, 04_MulEqMXOperator) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 1.0);
  A.setElement(0, 1, 4.0);

  A.setElement(1, 0, 2.0);
  A.setElement(1, 1, 5.0);

  A.setElement(2, 0, 3.0);
  A.setElement(2, 1, 6.0);

  S21Matrix B(2, 3);
  B.setElement(0, 0, 1.0);
  B.setElement(0, 1, -1.0);
  B.setElement(0, 2, 1.0);

  B.setElement(1, 0, 2.0);
  B.setElement(1, 1, 3.0);
  B.setElement(1, 2, 4.0);

  A *= B;

  /* Матрица С - объект для сравнения после выполнения метода */

  S21Matrix C(3, 3);

  C.setElement(0, 0, 9.0);
  C.setElement(0, 1, 11.0);
  C.setElement(0, 2, 17.0);

  C.setElement(1, 0, 12.0);
  C.setElement(1, 1, 13.0);
  C.setElement(1, 2, 22.0);

  C.setElement(2, 0, 15.0);
  C.setElement(2, 1, 15.0);
  C.setElement(2, 2, 27.0);

  EXPECT_TRUE(A.eqMatrix(C));
}

TEST(TestMul, 05_MulNumberOperator) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 1.0);
  A.setElement(0, 1, 4.0);

  A.setElement(1, 0, 2.0);
  A.setElement(1, 1, 5.0);

  A.setElement(2, 0, 3.0);
  A.setElement(2, 1, 6.0);

  S21Matrix B(2, 3);
  B.setElement(0, 0, 1.0);
  B.setElement(0, 1, -1.0);
  B.setElement(0, 2, 1.0);

  B.setElement(1, 0, 2.0);
  B.setElement(1, 1, 3.0);
  B.setElement(1, 2, 4.0);

  S21Matrix D(3, 3);

  D = A * B;

  /* Матрица С - объект для сравнения после выполнения метода */

  S21Matrix C(3, 3);

  C.setElement(0, 0, 9.0);
  C.setElement(0, 1, 11.0);
  C.setElement(0, 2, 17.0);

  C.setElement(1, 0, 12.0);
  C.setElement(1, 1, 13.0);
  C.setElement(1, 2, 22.0);

  C.setElement(2, 0, 15.0);
  C.setElement(2, 1, 15.0);
  C.setElement(2, 2, 27.0);

  EXPECT_TRUE(D.eqMatrix(C));
}

TEST(TestMul, 06_MulNumOperator) {
  double num = 5.5;
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix C(3, 2);

  C = A * num;

  /* Матрица B - объект для сравнения после выполнения метода */

  S21Matrix B(3, 2);
  B.setElement(0, 0, 0.0123456789 * num);
  B.setElement(0, 1, 0.1 * num);

  B.setElement(1, 0, 1.0 * num);
  B.setElement(1, 1, 1.1 * num);

  B.setElement(2, 0, 2.0 * num);
  B.setElement(2, 1, 2.1 * num);

  EXPECT_TRUE(C.eqMatrix(B));
}