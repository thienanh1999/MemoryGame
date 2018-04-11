#include "Generate.h"
#include <iostream>

Generate::Generate(int weight, int height) {
 x = weight;
 y = height;
}

void Generate::printhello() {
    std::cout << (x+y);
}
