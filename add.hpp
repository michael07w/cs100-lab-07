#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <sstream>
#include "base.hpp"

class Add : public Base {
    private:
        Base* left;
        Base* right;
        double result;
    public:
        Add(Base* l, Base* r) : Base() {
            left = l;
            right = r;
            result = 0;
        }
        virtual double evaluate() {
            // add each child, store in result, and return result
            result = left->evaluate() + right->evaluate();
            return (result);
        }
         virtual std::string stringify() {
            // surround entire operation with parentheses
            std::ostringstream sstream;
            sstream << "(" << left->stringify() << " + " << right->stringify() << ")";                                    return sstream.str();
        }                                                                                                
 };

#endif
