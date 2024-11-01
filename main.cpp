#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>

void solveQuadratic(const double a, const double b, const double c) {
    if (a == 0) {
        std::cout << "This is not a quadratic equation." << std::endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        const double root1 = (-b + sqrt(discriminant)) / (2 * a);
        const double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Two real roots: " << root1 << " and " << root2 << std::endl;
    } else if (discriminant == 0) {
        const double root = -b / (2 * a);
        std::cout << "One real root: " << root << std::endl;
    } else {
        const double realPart = -b / (2 * a);
        const double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "Two complex roots: "
                  << realPart << " + " << imaginaryPart << "i and "
                  << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

int main() {
    double a, b, c;
    std::string input;

    while (true) {
        std::cout << "Enter coefficients a, b, c (comma-separated) or type 'individual' to enter them one by one (or type 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }
        if (input == "individual") {
            std::cout << "Enter coefficient a: ";
            std::getline(std::cin, input);
            std::istringstream(input) >> a;

            std::cout << "Enter coefficient b: ";
            std::getline(std::cin, input);
            std::istringstream(input) >> b;

            std::cout << "Enter coefficient c: ";
            std::getline(std::cin, input);
            std::istringstream(input) >> c;
        } else {
            std::replace(input.begin(), input.end(), ',', ' ');
            if (!(std::istringstream(input) >> a >> b >> c)) {
                std::cout << "Invalid input! Please enter numbers in the format a, b, c." << std::endl;
                continue;
            }
        }

        solveQuadratic(a, b, c);
    }

    return 0;
}