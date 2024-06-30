#ifndef TENSER_CPP
#define TENSER_CPP
#include "../include/blackwall/tenser.hpp"
#include <algorithm>

namespace BLKW{
    template<typename T>
    Tenser<T>::Tenser(std::initializer_list<int> dimensions){
        this->dimensions = dimensions;
        int size = std::accumulate(dimensions.begin(),dimensions.end(), 1, [](int x, int y) { return x*y; });
        data = new T[size];
        compute_strides();
    }

    template<typename T>
    Tenser<T>::Tenser(const Tenser *other){
        this->dimensions = other->dimensions;
        int size = std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        data = new T[size];
        for(int i = 0 ; i < size ; i++)
            data[i] = other->data[i];

        compute_strides();
    }

    template<typename T>
    Tenser<T>::~Tenser(){
        delete[] data;
    }
    
    template<typename T>
    Tenser<T> Tenser<T>::zeros(std::initializer_list<int> dimensions){
        Tenser<T> tenser(dimensions);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::fill(tenser.data, end, 0);
        return tenser;
    }

    template<typename T>
    BLKW::Tenser<T> Tenser<T>::ones(std::initializer_list<int> dimensions){
        Tenser<T> tenser(dimensions);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::fill(tenser.data, end, 1);
        return tenser;
    }

    template<typename T>
    BLKW::Tenser<T> Tenser<T>::random(std::initializer_list<int> dimensions){
        Tenser<double> tenser(dimensions);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0, 1);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::for_each(start, end, [&dis, &gen](double &x) { x = dis(gen); });
        return tenser;
    }

    template <typename T>
    int Tenser<T>::shape(){
        return this->dimensions.size();
    }

    template <typename T>
    int Tenser<T>::size(){
        return std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
    }

    // template <typename T>
    // void Tenser<T>::compute_strides(){
    //     strides = std::vector<int>(dimensions.size());
    //     strides[dimensions.size() - 1] = 1;
    //     for(int i = dimensions.size() - 2; i >= 0; i--)
    //         strides[i] = strides[i + 1] * dimensions[i + 1];
    // }

    template <typename T>
    void Tenser<T>::compute_strides(){
        strides = std::vector<int>(dimensions.size());
        if (dimensions.size() > 0) {
            strides[dimensions.size() - 1] = 1;
            for(int i = dimensions.size() - 2; i >= 0; i--)
                strides[i] = strides[i + 1] * dimensions[i + 1];
        }
    }


    template <typename T>
    T* Tenser<T>::operator[](std::initializer_list<int> indices){

        if(indices.size() != dimensions.size()) 
            throw std::runtime_error("Invalid indices size");

        // for(int i = 0 ; i < indices.size() ; i++)
        //     if(indices.at(i) >= dimensions.at(i) || indices.at(i) < 0) 
        //         throw std::runtime_error("Invalid indices size");

        int i = 0;
        for(int multiIndex : indices){
            if(multiIndex >= dimensions[i] || 0 > multiIndex) throw std::runtime_error("Invalid indices size");
            i++;
        }
        
        int flatIndex = 0;
        // for(int i = 0 ; i < indices.size() ; i++)
        //     index += indices[i] * strides[i];

        i = 0;
        for(int multiIndex : indices){
            flatIndex += multiIndex * strides[i];
            i++;
        }
        return &data[flatIndex];
    }

}

#endif // TENSER_CPP