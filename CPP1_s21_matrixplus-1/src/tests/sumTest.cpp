#include "test.h"

TEST(TestSum, 00_Sum) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix B = A;

  A.sumMatrix(B);

  /* Матрица С - объект для сравнения после выполнения метода */

  S21Matrix C(3, 2);
  C.setElement(0, 0, 0.0246913578);
  C.setElement(0, 1, 0.2);

  C.setElement(1, 0, 2.0);
  C.setElement(1, 1, 2.2);

  C.setElement(2, 0, 4.0);
  C.setElement(2, 1, 4.2);

  EXPECT_TRUE(A.eqMatrix(C));
}

TEST(TestSum, 01_SumOperatorPlusEq) {
  S21Matrix A(3, 2);

  A.setElement(0, 0, 0.0123456789);
  A.setElement(0, 1, 0.1);

  A.setElement(1, 0, 1.0);
  A.setElement(1, 1, 1.1);

  A.setElement(2, 0, 2.0);
  A.setElement(2, 1, 2.1);

  S21Matrix B = A;

  /* Вызов конструктора переноса, что бы тоже поучаствовал в тестах */
  S21Matrix D(move(B));

  A += D;

  /* Матрица С - объект для сравнения после выполнения метода */

  S21Matrix C(3, 2);

  C.setElement(0, 0, 0.0246913578);
  C.setElement(0, 1, 0.2);

  C.setElement(1, 0, 2.0);
  C.setElement(1, 1, 2.2);

  C.setElement(2, 0, 4.0);
  C.setElement(2, 1, 4.2);

  EXPECT_TRUE(A.eqMatrix(C));
}

TEST(TestSum, 02_SumOperatorPlus) {
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

  S21Matrix B = A + C;

  /* Матрица D - объект для сравнения после выполнения метода */

  S21Matrix D(3, 2);

  D.setElement(0, 0, 0.0246913578);
  D.setElement(0, 1, 0.2);

  D.setElement(1, 0, 2.0);
  D.setElement(1, 1, 2.2);

  D.setElement(2, 0, 4.0);
  D.setElement(2, 1, 4.2);

  EXPECT_TRUE(B.eqMatrix(D));
}

TEST(TestSum, 03_SumThrow) {
  S21Matrix A(2, 3);
  S21Matrix B(4, 5);

  ASSERT_ANY_THROW(A.sumMatrix(B));
}

TEST(TestSum, 04_SumThrowOperator) {
  S21Matrix A(2, 3);
  S21Matrix B(4, 5);

  ASSERT_ANY_THROW(A + B);
}
