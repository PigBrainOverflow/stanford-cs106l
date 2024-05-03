// STUDENT

#include "hashmap.h"

// g++ -std=c++17 main.cpp -o main.exe

int main() {
    HashMap<int, int> hmap{
        {1, 2},
        {20, 12},
        {12, 1},
        {17, 1},
        {7, 9}
    };
    hmap.debug();
    for (auto it = hmap.begin(); it != hmap.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    hmap.erase(20);
    hmap.debug();
    return 0;
}