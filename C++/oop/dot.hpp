#ifndef DOT_HPP
#define DOT_HPP

#include <cmath>

class dot
{
    public:
        double distFromZero()
        {
            return std::sqrt(x*x + y*y); 
        }

        void setX(double x)
        {
            this->x = x;
        }

        void setY(double y)
        {
            this->y = y;
        }

        double getX()
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        dot(double x, double y) : x(x), y(y) {}
        dot() : dot(0.0, 0.0) {}
        
    private:
        double x,y;
};

#endif