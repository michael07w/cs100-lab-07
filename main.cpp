#include "factory.hpp"
#include <iostream>

int main(int argc, char** argv) {

    Factory f;
    Base* root = f.parse(argv + 1, argc - 1);
    
    if (root == nullptr)
	std::cout << "Invalid input!" << std::endl;
    else
	std::cout << root->stringify() << " = " << root->evaluate() << std::endl;

    return 0;
}
