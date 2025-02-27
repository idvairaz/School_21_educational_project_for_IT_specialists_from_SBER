#include "test.h"

TEST(TestSub, 00_Sub) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix C(3, 2);

  C.setElement(0, 0, 0.0246913578);
  C.setElement(0, 1, 0.2);

  C.setElement(1, 0, 2.0);
  C.setElement(1, 1, 2.2);

  C.setElement(2, 0, 4.0);
  C.setElement(2, 1, 4.2);

  C.subMatrix(A);

  EXPECT_TRUE(A.eqMatrix(C));
}

TEST(TestSub, 01_SubOperatorMinEq) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix C(3, 2);

  C.setElement(0, 0, 0.0246913578);
  C.setElement(0, 1, 0.2);

  C.setElement(1, 0, 2.0);
  C.setElement(1, 1, 2.2);

  C.setElement(2, 0, 4.0);
  C.setElement(2, 1, 4.2);

  C -= A;
  EXPECT_TRUE(A.eqMatrix(C));
}

TEST(TestSub, 02_SubOperatorMin) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix C(3, 2);

  C.setElement(0, 0, 0.0246913578);
  C.setElement(0, 1, 0.2);

  C.setElement(1, 0, 2.0);
  C.setElement(1, 1, 2.2);

  C.setElement(2, 0, 4.0);
  C.setElement(2, 1, 4.2);

  S21Matrix B = C - A;

  EXPECT_TRUE(B.eqMatrix(A));
}

TEST(TestSum, 03_SubThrowOperator) {
  S21Matrix A(2, 3);
  S21Matrix B(4, 5);

  ASSERT_ANY_THROW(A - B);
}
TEST(TestSum, 04_SubEqThrowOperator) {
  S21Matrix A(2, 3);
  S21Matrix B(4, 5);

  ASSERT_ANY_THROW(A -= B);
}
