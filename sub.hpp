#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <sstream>
#include "base.hpp"

class Sub : public Base {
    private:
        Base* left;
        Base* right;
        double result;
    public:
        Sub(Base* l, Base* r) : Base() {
            left = l;
            right = r;
            result = 0;
        }
        virtual double evaluate() {
            result = left->evaluate() - right->evaluate();
            return (result);
        }
        virtual std::string stringify() {
            std::ostringstream sstream;
            sstream << "(" << left->stringify() << " - " << right->stringify() << ")";
            return sstream.str();
        }
};
#endif
