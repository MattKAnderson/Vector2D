#include <iostream>

#include "Vector2D.hpp"


int main() {
    Vector2D<float> float_vec(12.7, 13.0);

    Vector2D<double> double_vec = Vector2D<double>(float_vec);

    std::cout << "float vec: " << float_vec << std::endl;
    std::cout << "double vec: " << double_vec << std::endl;
}