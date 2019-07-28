#include <iostream>
#include <cmath>

const int rangeUpperValue = 600;
const int rangeLowerValue = -600;

double getParameter(char parameter) {
  std::cout << "Input coefficient in range [-600..600] <" << parameter << ">: ";
  int coeff_a;
  while (!(std::cin >> coeff_a) || !(coeff_a >= rangeLowerValue && coeff_a <= rangeUpperValue)) {
    std::cout << "Error! Re-Input coefficient <" << parameter << ">" << std::endl;
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
  }
  return coeff_a;
}

int func_discr(int a, int b, int c) {
  const int discriminant = b * b - 4 * a * c;
  return discriminant;
}

int main() {
  std::cout << "The quadratic equation has the following form: ax^2 + bx + c" << std::endl << std::endl;

  const int first_koef = getParameter('a');
  const int sec_koef = getParameter('b');
  const int third_koef = getParameter('c');

  const int discriminant = func_discr(first_koef, sec_koef, third_koef);
  if (discriminant > 0) {
    const int dominator = 2 * first_koef;
    const int result_1 = (-sec_koef + sqrt(discriminant)) / dominator;
    const int result_2 = (-sec_koef - sqrt(discriminant)) / dominator;

    result_1 == result_2 ? std::cout << "X = " << result_1 << std::endl : std::cout << "X1 = " << result_1 << "\tX2 = " << result_2 << std::endl;
  } else {
    std::cout << "CRITICAL ERROR! D < 0!" << std::endl;
  }
  
  return 0;   
}

