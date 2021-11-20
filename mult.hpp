#ifndef __MULT_HPP__
#define __MULT_HPP__

#include <sstream>
#include "base.hpp"

class Mult : public Base {
    private:
        Base* left;
        Base* right;
        double result;
    public:
        Mult(Base* l, Base* r) : Base() {
            left = l;
            right = r;
            result = 0;
        }
        virtual double evaluate() {
            // multiply each child, store in result, and return result
            result = left->evaluate() * right->evaluate();
            return (result);
        }
        virtual std::string stringify() {
            // surround entire operation with parentheses
            std::ostringstream sstream;
	    sstream << "(" << left->stringify() << " * " << right->stringify() << ")";
            return sstream.str();
	}
};

#endif //__MULT_HPP__
