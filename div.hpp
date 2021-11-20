#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <sstream>
#include "base.hpp"

struct DivByZero : public std::exception {
    const char* what() const throw() {
	return "Cannot divide by zero!";
    }
};

class Div : public Base {
    private:
	Base* left;
	Base* right;
	double result;
    public:
	Div(Base* l, Base* r) : Base() {
	    left = l;
	    right = r;
	    result = 0;
	}
	virtual double evaluate() {
	    if (right->evaluate() == 0) {
		throw DivByZero();
	    }
	    result = left->evaluate() / right->evaluate();
	    return result;
	}
	virtual std::string stringify() {
	    // surround entire operation with parentheses
	    std::ostringstream sstream;
	    sstream << "(" << left->stringify() << " / " << right->stringify() << ")";
	    return sstream.str();
	}
};

#endif //__DIV_HPP__
