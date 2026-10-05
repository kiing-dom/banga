#include <iostream>
#include <cmath>
#include <string>

constexpr double kPi = 3.14159265358979;

double wobble(double t, double frequency, double amount) {
    double value = amount * std::sin((2.0*kPi) * frequency * t);

    // std::cout << "wobble(): t = " << t
    //           << ", value = " << value << '\n';

    return value;
}

int toColumn(double value, double amount, int width) {
    double normalized = (value + amount) / (2.0 * amount);
    int column = static_cast<int>(normalized * width);

    // std::cout << "toColumn(): value = " << value
    //           << ", normalized = " << normalized
    //           << ", column = " << column << '\n';
    return column;
}

double degreesToRadians(double degrees) {
    return degrees * (kPi / 180);
}

int main() {
    double frequency = 1.0;
    double amount = 10.0;
    int width = 40;

    // std::cout << "frequency = " << frequency << '\n';
    // std::cout << "amount = " << amount << '\n';
    // std::cout << "width = " << width << "\n\n";

    for (double t = 0.0; t <= 0.6; t += 0.1) {
        double value = wobble(t, frequency, amount);
        int column = toColumn(value, amount, width);

        std::cout << std::string(column, ' ') << "*\n\n";
    }
}
