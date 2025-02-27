#include "test.h"

TEST(TestMul, 00_transpose) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 1.0);
  A.setElement(0, 1, 4.0);

  A.setElement(1, 0, 2.0);
  A.setElement(1, 1, 5.0);

  A.setElement(2, 0, 3.0);
  A.setElement(2, 1, 6.0);

  S21Matrix C(2, 3);

  C = A.transpose();
  /* Матрица B - объект для сравнения после выполнения метода */
  S21Matrix B(2, 3);
  B.setElement(0, 0, 1.0);
  B.setElement(0, 1, 2.0);
  B.setElement(0, 2, 3.0);

  B.setElement(1, 0, 4.0);
  B.setElement(1, 1, 5.0);
  B.setElement(1, 2, 6.0);

  EXPECT_TRUE(C.eqMatrix(B));
}
