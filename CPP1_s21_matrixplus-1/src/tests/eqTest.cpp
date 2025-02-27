#include "test.h"

TEST(TestEq, 00_goodSizeAndParam) {
  S21Matrix m1;
  S21Matrix m2;
  EXPECT_TRUE(m1.eqMatrix(m2));
}
TEST(TestEq, 02_badSize) {
  S21Matrix m1(2, 3);
  S21Matrix m3(4, 3);
  EXPECT_FALSE(m1.eqMatrix(m3));
}

TEST(TestEq, 03_false) {
  S21Matrix m1{3, 4};
  S21Matrix m2{3, 4};

  m1.setElement(2, 2, 5.5);
  EXPECT_FALSE(m1.eqMatrix(m2));
}

TEST(TestEq, 04_true) {
  S21Matrix m1{3, 4};
  S21Matrix m2{3, 4};
  for (int i = 0; i < m1.getRows(); ++i) {
    for (int j = 0; j < m1.getCols(); ++j) {
      m1.setElement(i, j, j);
      m2.setElement(i, j, j);
    }
  }
  EXPECT_TRUE(m1.eqMatrix(m2));
}
TEST(TestEq, 05_goodSizeAndParamOperator) {
  S21Matrix m1(2, 3);
  S21Matrix m2(2, 3);
  EXPECT_TRUE(m1 == m2);
}
TEST(TestEq, 06_goodParamOperatorEq) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix C(3, 2);

  C.setElement(0, 0, 0.0123456789);
  C.setElement(0, 1, 0.1);

  C.setElement(1, 0, 1.0);
  C.setElement(1, 1, 1.1);

  C.setElement(2, 0, 2.0);
  C.setElement(2, 1, 2.1);
  EXPECT_TRUE(A == C);
}

TEST(TestEq, 07_goodParamOperatorEq) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix C;
  C = A;
  for (int i = 0; i < A.getRows(); ++i) {
    for (int j = 0; j < A.getCols(); ++j) {
      EXPECT_DOUBLE_EQ(C(i, j), A(i, j));
    }
  };
}

TEST(TestEq, 08_self_Eq) {
  S21Matrix A(2, 3);
  A = A;

  ASSERT_EQ(A.getRows(), 2);
  ASSERT_EQ(A.getCols(), 3);
}
