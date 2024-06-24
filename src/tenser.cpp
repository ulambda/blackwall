#ifndef TENSER_CPP
#define TENSER_CPP
#include "../include/blackwall/tenser.hpp"


namespace BLKW{
    template <class T>
    Tenser<T>::Tenser(){
        this->dimensions = {0};
    }

    template <class T>
    Tenser<T>::Tenser(const Tenser *other){
        this->dimensions = other->dimensions;
        this->data = other->data;
    }

    template <class T>
    Tenser<T> Tenser<T>::zeros(int dimensions[]){
        Tenser<T> tenser;
        tenser.dimensions = dimensions;
        tenser.data = std::vector<T>(dimensions[0]);
        return tenser;
    }

    template <class T>
    Tenser<T> Tenser<T>::ones(int dimensions[]){
        Tenser<T> tenser;
        tenser.dimensions = dimensions;
        tenser.data = std::vector<T>(dimensions[0], 1);
        return tenser;
    }
}

#endif // TENSER_CPP