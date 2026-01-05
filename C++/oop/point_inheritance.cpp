#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <string>

class Point_3D {
    public:

        Point_3D(float x, float y, float z, const std::string &name) : x(x), y(y), z(z), name(name), id(curr_id++) {}
        Point_3D() : Point_3D(0.0f, 0.0f, 0.0f, "a") {}
        Point_3D(Point_3D &other) : x(other.x), y(other.y), z(other.z), name(other.name), id(other.id) {}
        ~Point_3D() {}

        void set_x(float x) { this -> x = x; }
        void set_y(float y) { this -> y = y; }
        void set_z(float z) { this -> z = z; }

        float get_x() const { return x; } 
        float get_y() const { return y; }
        float get_z() const { return z; }

        virtual float get_rv() const { return sqrtf(x*x + y*y + z*z); }

        void set_name(std::string name) { this -> name = name; }
        std::string get_name() { return name; }

    protected:

        int id;
        static int curr_id;
        std::string name;
        float x;
        float y;
        Point_3D(float x, float y, float z, const std::string &name, int id) : x(x), y(y), z(z), name(name), id(id) {}

    private:

        float z;
};

class Point_2D : public Point_3D {
    public:

        Point_2D(float x, float y, std::string name) : Point_3D(x, y, 0.0f, name) {}
        Point_2D() : Point_3D() {}
        Point_2D(Point_2D &other) : Point_3D(other.x, other.y, 0.0f, other.name, other.id) {}
        ~Point_2D() {}

        float get_rv() const override { return sqrtf(x*x + y*y); }

    private:

        void set_z(float z) {}
        float get_z() const {}
};

int Point_3D::curr_id = 0;

#endif