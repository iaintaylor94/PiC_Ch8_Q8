// Program to calculate the roots of a quadratic function
// To test the program try:
// a = 1; b = 3; c = 0; (discriminant > 0)
// a = 1; b = 2; c = 1; (discriminant = 0)
// a = 1; b = 0; c = 2; (discriminamt < 0)

#include <stdio.h>

// Declare Functions
double discriminant (double, double, double); // Function to calculate the discriminant of a quadratic equation
double absoluteValue (double); // Function to calculate the absolute value of a number
double squareRoot (double); // Function to calculate the square root of a number
void quadraticFormula (double, double, double); // Function to calculate the roots of a quadratic equation

int main(void) {

  // Get input 
  double a, b, c;
  printf ("Enter quadratic constants <a> <b> <c>:  ");
  scanf ("%lf%lf%lf", &a, &b, &c);

  // Calculate and Print roots
  quadraticFormula (a, b, c);
}

// Define Functions
double discriminant (double a, double b, double c) {
  double disc = (b * b) - (4 * a * c);
  printf ("disc = %lf\n", disc);
  return (disc);
}

double absoluteValue (double x) {
  if (x < 0)
    x *= -1;

  return x;
}

// Does not compute negative numbers correctly (misses out 'i')
// Thus programs calling this function must check for negative numbers before calling it and process the number appropriately
double squareRoot (double x) {
  double guess = 1;
  
  if (x < 0) {
    x *= -1;

    const double epsilon = .00001;

    while (absoluteValue (guess * guess - x) >= epsilon) {
      guess = (x / guess + guess) / 2.0;
    }

    guess *= -1;
    
  }
  else {
    const double epsilon = .00001;

    while (absoluteValue (guess * guess - x) >= epsilon) {
      guess = (x / guess + guess) / 2.0;
    }
  }

  return guess;
}

void quadraticFormula (double a, double b, double c) {
  // Test for discriminant < 0 - 2 roots - complex conjugates of each other
  if (discriminant (a, b, c) < 0) {
    double realPart = -b / 2 * a;
    double imaginaryPart = absoluteValue (squareRoot (discriminant (a, b, c)) / 2 * a);
    printf ("realPart = %lf\n", realPart);
    printf ("imaginaryPart = %lf\n", imaginaryPart);
    
    printf ("Discriminant is %lf\n", discriminant (a, b, c));
    printf ("The roots of %lf, %lf and %lf are \"%lf + %lfi\" and \"%lf - %lfi\"", a, b, c, realPart, imaginaryPart, realPart, imaginaryPart);
  }
  // Test for discriminant = 0 - 1 root 
  else if (discriminant (a, b, c) == 0) {
    double root = (- b + squareRoot (discriminant(a, b, c))) / (2 * a);
    
    printf ("Discriminant is %lf\n", discriminant (a, b, c));
    printf ("The root of %lf, %lf and %lf is %lf\n", a, b, c, root);
  }
  // Test for discriminant > 0 - 2 roots - distinct
  else if (discriminant > 0) {
    double positiveRoot = (- b + squareRoot (discriminant(a, b, c))) / (2 * a);
    double negativeRoot = (- b - squareRoot (discriminant(a, b, c))) / (2 * a);

    printf ("Discriminant is %lf\n", discriminant(a, b, c));
    printf ("The positive root is:  %lf\n", positiveRoot);
    printf ("The negative root is:  %lf\n", negativeRoot);
  }
}