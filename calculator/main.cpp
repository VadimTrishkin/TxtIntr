#include <iostream>
#include <cmath>
#include <string>

void printUsage() {
    std::cout << "Usage: calculator -o <operation> <value>" << std::endl;
    std::cout << "Operations: arcsin, arccos" << std::endl;
}

double toDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    std::string operation = argv[2];
    double value = std::stod(argv[3]);  // Преобразуем строку в число

    if (operation == "arcsin") {
        if (value < -1 || value > 1) {
            std::cerr << "Invalid value for arcsin: " << value << ". Must be in [-1, 1]." << std::endl;
            return 1;
        }
        double radians = std::asin(value);
        double degrees = toDegrees(radians);
        std::cout << "arcsin(" << value << ") in radians: " << radians << std::endl;
        std::cout << "arcsin(" << value << ") in degrees: " << degrees << std::endl;
    } else if (operation == "arccos") {
        if (value < -1 || value > 1) {
            std::cerr << "Invalid value for arccos: " << value << ". Must be in [-1, 1]." << std::endl;
            return 1;
        }
        double radians = std::acos(value);
        double degrees = toDegrees(radians);
        std::cout << "arccos(" << value << ") in radians: " << radians << std::endl;
        std::cout << "arccos(" << value << ") in degrees: " << degrees << std::endl;
    } else {
        printUsage();
        return 1;
    }

    return 0;
}
