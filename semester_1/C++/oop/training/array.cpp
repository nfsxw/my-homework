#include "array.hpp"

Array::Array(float *src, int n) {
    this ->n = n;
    this->m = new float [n];
    if(!src) {
        for(int i=0; i<n; i++) this->m[i] = 0;
    } else {
        for(int i=0;  i<n; i++) this->m[i] = src[i];
    }
}

    Array::~Array() {
        if(m) {
            delete []m;
            m = nullptr;
        }
    }

int main()
{

}