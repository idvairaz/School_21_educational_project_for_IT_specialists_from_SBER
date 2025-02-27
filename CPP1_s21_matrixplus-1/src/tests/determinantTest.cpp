#include "test.h"

TEST(TestDet, 00_determinant0) {
  S21Matrix mat(3, 3);
  mat.setElement(0, 0, 0);
  mat.setElement(0, 1, 0);
  mat.setElement(0, 2, 0);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 0);
  mat.setElement(1, 2, 0);

  mat.setElement(2, 0, 0);
  mat.setElement(2, 1, 5);
  mat.setElement(2, 2, 0);

  double det = mat.determinant();

  EXPECT_TRUE(det == 0);
}
TEST(TestDet, 01_determinant1) {
  S21Matrix mat(1, 1);
  mat.setElement(0, 0, 78);

  double det = mat.determinant();

  EXPECT_TRUE(det == 78);
}
TEST(TestDet, 02_determinant2) {
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

  double det = mat.determinant();

  EXPECT_TRUE(det == 0);
}

TEST(TestDet, 03_determinant3) {
  S21Matrix mat(3, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 0);
  mat.setElement(1, 1, 1);
  mat.setElement(1, 2, 4);

  mat.setElement(2, 0, 5);
  mat.setElement(2, 1, 6);
  mat.setElement(2, 2, 0);

  double det = mat.determinant();

  EXPECT_TRUE(det == 1);
}
TEST(TestDet, 04_determinant4) {
  S21Matrix mat(3, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 1);
  mat.setElement(1, 1, 22);
  mat.setElement(1, 2, 3);

  mat.setElement(2, 0, 18);
  mat.setElement(2, 1, 2);
  mat.setElement(2, 2, 3);

  double det = mat.determinant();

  EXPECT_TRUE(det == -1020);
}
TEST(TestDet, 05_determinant5) {
  S21Matrix mat(2, 3);
  mat.setElement(0, 0, 1);
  mat.setElement(0, 1, 2);
  mat.setElement(0, 2, 3);

  mat.setElement(1, 0, 1);
  mat.setElement(1, 1, 22);
  mat.setElement(1, 2, 3);
  ASSERT_ANY_THROW(mat.determinant());
}