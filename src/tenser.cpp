#ifndef TENSER_CPP
#define TENSER_CPP
#include "../include/blackwall/tenser.hpp"
#include <algorithm>
#include <deque>
#include <functional>

namespace BLKW{
    template<typename T>
    Tenser<T>::Tenser(std::initializer_list<int> dimensions){
        this->dimensions = dimensions;
        int size = std::accumulate(dimensions.begin(),dimensions.end(), 1, [](int x, int y) { return x*y; });
        data = new T[size];
        compute_strides();
    }

    template<typename T>
    Tenser<T>::Tenser(const Tenser& other){
        this->dimensions = other.dimensions;
        int size = std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        data = new T[size];
        for(int i = 0 ; i < size ; i++)
            this->data[i] = other.data[i];
        compute_strides();
    }


    template<typename T>
    Tenser<T>::~Tenser(){
        delete[] data;
    }

    
    template<typename T>
    Tenser<T> Tenser<T>::defaults(std::initializer_list<int> dimensions) {
        Tenser<T> tenser(dimensions);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::fill(tenser.data, end, new T());
        return tenser;
    }
    
    template<typename T>
    Tenser<T> Tenser<T>::zeros(std::initializer_list<int> dimensions){
        Tenser<T> tenser(dimensions);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::fill(tenser.data, end, 0.0);
        return tenser;
    }

    template<typename T>
    BLKW::Tenser<T> Tenser<T>::ones(std::initializer_list<int> dimensions){
        Tenser<T> tenser(dimensions);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::fill(tenser.data, end, 1.0);
        return tenser;
    }

    template<typename T>
    BLKW::Tenser<T> Tenser<T>::randoms(std::initializer_list<int> dimensions){
        Tenser<double> tenser(dimensions);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0);
        auto start = tenser.data;
        auto end = tenser.data + std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        std::for_each(start, end, [&dis, &gen](double &x) { x = dis(gen); });
        return tenser;
    }

    template <typename T>
    std::vector<int> BLKW::Tenser<T>::shape() const{
        return this->dimensions;
    }

    template <typename T>
    int BLKW::Tenser<T>::size() const{
        return std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
    }

    template <typename T>
    int BLKW::Tenser<T>::depth() const{
        return this->dimensions.size();
    }

    template <typename T>
    void BLKW::Tenser<T>::print() const{
    }



    template <typename T>
    void Tenser<T>::compute_strides(){
        strides = std::vector<int>(dimensions.size());
        strides[dimensions.size() - 1] = 1;
        for(int i = dimensions.size() - 2; i >= 0; i--)
            strides[i] = strides[i + 1] * dimensions[i + 1];
    }

    template <typename T>
    int Tenser<T>::flatten_index(std::initializer_list<int> indices){
        int flatIndex = 0;
        int i = 0;
        for(int multiIndex : indices){
            flatIndex += multiIndex * strides[i];
            i++;
        }
        return flatIndex;
    }

    template <typename T>
    T* Tenser<T>::operator[](std::initializer_list<int> indices){
        //check invariants
        if(indices.size() != dimensions.size()) 
            throw std::runtime_error("Invalid indices size");

        int i = 0;
        for(int multiIndex : indices){
            if(multiIndex >= dimensions[i] || 0 > multiIndex) 
                throw std::runtime_error("Invalid indices size");
            i++;
        }
        
        return &data[flatten_index(indices)];
    }

    template <typename T>
    Tenser<T> &Tenser<T>::operator=(Tenser<T>& other){
        if(this == &other) return *this;
        delete[] this->data;
        this->dimensions = other.dimensions;
        int size = std::accumulate(dimensions.begin(), dimensions.end(), 1, [](int x, int y) { return x*y; });
        data = new T[size]();
        for(int i = 0 ; i < size ; i++)
            this->data[i] = other.data[i];
        compute_strides();
        return *this;
    }

    
    template <typename T>
    Tenser<T>* Tenser<T>::merge(const Tenser<T>& other, std::function<T(T, T)> operation){
        if(this->dimensions != other.dimensions) 
            throw std::runtime_error("Invalid dimensions");
        Tenser<T> *result = new Tenser<T>(this);
        for(int i = 0 ; i < this->size() ; i++)
            result->data[i] = operation(this->data[i], other.data[i]);
        return result;
    }

    template <typename T>
    Tenser<T>* Tenser<T>::operator+(Tenser<T> other){
        return merge(other, [](T a, T b) { return a + b; });
    }

    template <typename T>
    Tenser<T>* Tenser<T>::operator-(Tenser<T> other){
        return merge(other, [](T a, T b) { return a - b; });
    }

    template <typename T>
    Tenser<T>* Tenser<T>::operator*(Tenser<T> other){
        return merge(other, [](T a, T b) { return a * b; });
    }

    template <typename T>
    Tenser<T>* Tenser<T>::operator/(Tenser<T> other){
        return merge(other, [](T a, T b) { return a / b; });
    }

    template <typename T>
    void Tenser<T>::replace(std::initializer_list<int> indices, T value){
        data[flatten_index(indices)] = value;
    }


}

#endif // TENSER_CPP