#ifndef TENSER_HPP
#define TENSER_HPP

#include <vector>
#include <initializer_list>
#include <random> 
#include <numeric>
#include <functional>

namespace BLKW{
    template <class T>
    class Tenser{

        private:
            std::vector<int> dimensions;
            T* data;
            std::vector<int> strides;
            void compute_strides();
            Tenser(std::initializer_list<int> dimensions);
            Tenser(std::initializer_list<int> dimensions, int value);

        public:
            
            Tenser(const Tenser *other);
            ~Tenser();
            static Tenser<T> zeros(std::initializer_list<int> dimensions); 
            static Tenser<T> ones(std::initializer_list<int> dimensions);
            static Tenser<T> random(std::initializer_list<int> dimensions);
            static Tenser<T> garbages(std::initializer_list<int> dimensions);
            static Tenser<T> defaults(std::initializer_list<int> dimensions);

            int size();
            int shape();
            int depth();
            void print();

            Tenser<T>* merge(const Tenser<T>& other, std::function<T(T, T)> operation);
            Tenser<T>* for_each(std::function<T(T, T)> operation);
            T* operator[](std::initializer_list<int> indices);
            Tenser<T>& operator=(const Tenser<T>& other);
            Tenser<T>* operator+(Tenser<T> other);
            Tenser<T>* operator-(Tenser<T> other);
            Tenser<T>* operator*(Tenser<T> other);
            Tenser<T>* operator/(Tenser<T> other);

            // Tenser<T>* operator+(T scalar);
            // Tenser<T>* operator-(T scalar);
            // Tenser<T>* operator*(T scalar);
            // Tenser<T>* operator/(T scalar);

            // Tenser<T>& operator+=(const Tenser<T>& other);
            // Tenser<T>& operator-=(const Tenser<T>& other);
            // Tenser<T>& operator*=(const Tenser<T>& other);
            // Tenser<T>& operator/=(const Tenser<T>& other);





            

    };
}

















#endif // TENSER_HPP