#ifndef __POW_HPP__
#define __POW_HPP__

#include <sstream>
#include <cmath>
#include "base.hpp"

struct NegBase : public std::exception {
    const char* what() const throw() {
	return "Cannot use a negative base for pow!";
    }
};

class Pow : public Base {
    private:
        Base* left;
        Base* right;
        double result;
    public:
        Pow(Base* l, Base* r) : Base() {
            left = l;
            right = r;
            result = 0;
        }
        virtual double evaluate() {
	    if (left->evaluate() < 0) {
               throw NegBase();
            }
            result = pow(left->evaluate(), right->evaluate());
            return (result);
        }
        virtual std::string stringify() {
            std::ostringstream sstream;
            sstream << "(" << left->stringify() << " ** " << right->stringify() << ")";
            return sstream.str();
        }
};
#endif
