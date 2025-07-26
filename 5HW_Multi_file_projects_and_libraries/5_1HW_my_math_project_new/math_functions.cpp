#include "math_functions.h"
#include <cmath> // Для pow()

// Реализация сложения
double add(double a, double b) {
    return a + b;
}

// Реализация вычитания
double subtract(double a, double b) {
    return a - b;
}

// Реализация умножения
double multiply(double a, double b) {
    return a * b;
}

// Реализация деления
double divide(double a, double b) {
    if (b == 0) {
        return 0; // Деление на ноль — не будем выводить ошибку здесь
    }
    return a / b;
}

// Реализация возведения в степень
double power(double base, double exponent) {
    return pow(base, exponent);
}