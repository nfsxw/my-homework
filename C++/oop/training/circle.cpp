#include <iostream>

class Shape {
public:
    double x,y;
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Circle: public Shape {
public:
    double area() {
    return 3.14 * radius * radius;
    }

    double perimeter() {
        return 3.14 * radius * 2;
    }

    Circle() {
        radius = 1;
    }

    Circle(double r) {
        radius = r;
    }

    void setRadius(double r) {
        if(r > 0) {
            radius = r;
        } else {
            std::cout << "Radius must be positive!" << std::endl;
        }
    }

    double getRadius() {
        return radius;
    }

private:
    double radius;
};

int main(){
    Circle o1;
    Circle o2;

    o1.setRadius(-5);
    o1.setRadius(5);
    o2.setRadius(10);
    o1.x = 52;
    o1.y = 81;
    o1.move(5, 3);

    std::cout << "Position of o1 center is: (" << o1.x << "; " << o1.y << ")" << std::endl; 
    std::cout << "Your radiuses are: " << "1) "<< o1.getRadius() << " 2) " << o2.getRadius() << "\n" <<std::endl;
    std::cout << "Area of circle 1: "<< o1.area() << std::endl;
    std::cout << "Perimeter of circle 1: "<< o1.perimeter() << "\n" << std::endl; 
    std::cout << "Area of circle 2: "<< o2.area() << std::endl;
    std::cout << "Perimeter of circle 2: "<< o2.perimeter() << std::endl; 
}