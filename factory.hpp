#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <stdexcept>
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include <string>
#include <string.h>

class Factory {
    private:
	Base* left;
	Base* right;
	Base* root;
    public:
	Base* parse(char** input, int length);
};

Base* Factory::parse(char** input, int length) {
    // Return nullptr if there are insufficient args
    if (length % 2 == 0)
	return nullptr;

    // Initialize left, right, and root Base pointers
    left = nullptr;
    right = nullptr;
    root = nullptr;

    // Iterate through each operator
    for (int i = 1; i < length; i += 2) {
	// If left child is null pointer, store previous number in left child pointer
	if (left == nullptr) {
	    try {
		std::string str_left(input[i - 1]);
                left = new Op(stod(str_left));
	    }
	    catch(const std::invalid_argument& ia) {
		return nullptr;
	    }
	}
	// Otherwise, store root in left child pointer
	else {
	    left = root;
	}

	// Store next number in right child pointer
	try {
	    std::string str_right(input[i + 1]);
            right = new Op(stod(str_right));
	}
	catch(const std::invalid_argument& ia) {
	    return nullptr;
	}

	// Check which operator is present
	if (strcmp(input[i], "+") == 0) {
	    root = new Add(left, right);
	}
        else if (strcmp(input[i], "-") == 0) {
	    root = new Sub(left, right);
	}
	else if (strcmp(input[i], "*") == 0) {
	    root = new Mult(left, right);
	}
	else if (strcmp(input[i], "**") == 0) {
	    root = new Pow(left, right);
	}
	else if (strcmp(input[i], "/") == 0) {
	    root = new Div(left, right);
	}
	else {
	    // Return null pointer if input is invalid.
	    return nullptr;
	}
    }
    
    return root;
}

#endif //__FACTORY_HPP__
