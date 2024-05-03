#include "NDArray.h"

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor
 * Must have a default constructor
    - i.e. constructor overloading
 * Must have private members (functions and/or variables)
 * Must have public members (functions)
 * Must have at least one getter function
 * Must have at least one setter function
 */

int main() {
    NDArray<double> a({2, 3, 4}, 1.0);
    std::cout << a.size() << std::endl;
    a[{1, 1, 1}] = 0.0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                std::cout << a[{i, j, k}] << " ";
            }
        }
    }
    std::cout << std::endl;
    return 0;
}