#include <iostream>
#include <cmath>

int getParameter(char parameter) {
  std::cout << "Input coefficient in range [-600..600] <" << parameter << ">: ";
  int coeff_a;
  const int RANGE_UPPER_VALUE = 600;
  const int RANGE_LOWER_VALUE = -600;
  while (!(std::cin >> coeff_a) || (coeff_a < RANGE_LOWER_VALUE || coeff_a > RANGE_UPPER_VALUE)) {
    std::cout << "Error! Re-Input coefficient <" << parameter << ">" << std::endl;
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
  }
  return coeff_a;
}

auto func_discr(int a, int b, int c) {
  return b * b - 4 * a * c;
}

int main() {
  std::cout << "The quadratic equation has the following form: ax^2 + bx + c" << std::endl << std::endl;

  const int FIRST_KOEF = getParameter('a');
  const int SEC_KOEF = getParameter('b');
  const int THIRD_KOEF = getParameter('c');

  const auto DISCRIMINANT = func_discr(FIRST_KOEF, SEC_KOEF, THIRD_KOEF);
  if (DISCRIMINANT > 0) {
    const int DOMINATOR = 2 * FIRST_KOEF;
    const double RESULT_1 = (-SEC_KOEF + sqrt(DISCRIMINANT)) / DOMINATOR;
    const double RESULT_2 = (-SEC_KOEF - sqrt(DISCRIMINANT)) / DOMINATOR;

    if (RESULT_1 == RESULT_2) {
      std::cout << "X = " << RESULT_1 << std::endl;
    } else {
      std::cout << "X1 = " << RESULT_1 << "\tX2 = " << RESULT_2 << std::endl;
    }
  } else {
    std::cout << "CRITICAL ERROR! D < 0!" << std::endl;
  }

  return 0;   
}

