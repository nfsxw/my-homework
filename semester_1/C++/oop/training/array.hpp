#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array{
    public:
        Array(float *src, int n) {}
        Array(int n) : Array(nullptr, n) {}
        Array(Array &other) : Array(other.m, other.n) {}
        ~Array() {}
    private:
        float *m = nullptr;
        int n = 0;
};

#endif