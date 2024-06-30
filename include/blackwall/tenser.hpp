#ifndef TENSER_HPP
#define TENSER_HPP

#include <vector>
#include <initializer_list>
#include <random> 
#include <numeric>

namespace BLKW{
    template <class T>
    class Tenser{

        private:
            std::vector<int> dimensions;
            T* data;
            std::vector<int> strides;
            void compute_strides();

        public:
            Tenser(std::initializer_list<int> dimensions);
            Tenser(const Tenser *other);
            ~Tenser();
            static Tenser<T> zeros(std::initializer_list<int> dimensions); 
            static Tenser<T> ones(std::initializer_list<int> dimensions);
            static Tenser<T> random(std::initializer_list<int> dimensions);

            int shape();
            int size();

            T* operator[](std::initializer_list<int> indices);
            Tenser<T>& operator=(const Tenser<T>& other);

            Tenser<T>* operator+(Tenser<T> other);
            Tenser<T>* operator-(Tenser<T> other);
            Tenser<T>* operator*(Tenser<T> other);
            Tenser<T>* operator/(Tenser<T> other);


            

    };
}

















#endif // TENSER_HPP