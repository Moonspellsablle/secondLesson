#include <iostream>
#include <cmath>

//Prototype
double getParameter(char parameter);
double func_discr(double a, double b, double c, double discriminant);

double getParameter(char parameter) {
  do {
    std::cout << "Please enter '" << parameter << "' in range[-600..600]: " << std::endl;
    double koef;
    if(std::cin >> koef) {
      if (koef >= -600 && koef <= 600) {
        return koef;
      }
    } else {
      std::cout << "Only digit is avalible for parameter value!!!";
      throw 1;
    }
  }
  while(true);
}

double func_discr(double a, double b, double c, double discriminant) {
  discriminant = b * b - 4 * a * c;
  if(discriminant < 0) {
    std::cout << "CRITICAL ERROR! D < 0!" << std::endl;
    return discriminant;
  } else {         
    return discriminant;
  }
}

int main() {
  double first_koef = 0, sec_koef = 0, third_koef = 0;
  double discriminant = 0;
  double result_1 = 0, result_2 = 0;

  std::cout << "The quadratic equation has the following form: ax^2 + bx + c" << std::endl << std::endl;

  first_koef = getParameter('a');
  sec_koef = getParameter('b');
  third_koef = getParameter('c');

  discriminant = func_discr(first_koef, sec_koef, third_koef, discriminant);
  if (discriminant > 0) {
    result_1 = (-sec_koef + sqrt(discriminant)) / 2 * first_koef;
    result_2 = (-sec_koef - sqrt(discriminant)) / 2 * first_koef;

    if (result_1 == result_2) {
    	std::cout << "X = " << result_1 << std::endl;
    } else {
    	std::cout << "X1 = " << result_1 << "\tX2 = " << result_2 << std::endl;
    }
  }
  
  return 0;   
}

