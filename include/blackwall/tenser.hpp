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
            int flatten_index(std::initializer_list<int> indices);
        public:
            Tenser(std::initializer_list<int> dimensions);
            //Tenser(std::initializer_list<std::initializer_list<T>> dimensions);
            Tenser(const Tenser& other) ;
            ~Tenser();
            static Tenser<T> defaults(std::initializer_list<int> dimensions);
            static Tenser<T> zeros(std::initializer_list<int> dimensions); 
            static Tenser<T> ones(std::initializer_list<int> dimensions);
            static Tenser<T> randoms(std::initializer_list<int> dimensions);

            /**
             * @brief number of items a tenser can hold
             */
            int size() const;
            /**
             * @brief dimensions of the tenser as a vector of sizes indexed by the depth
             */
            std::vector<int> shape() const;
            /**
             * the dimensionality of the tenser
             */
            int depth() const;
            /**
             * prints the contents of the tenser
             */
            void print() const;
            
            T* operator[](std::initializer_list<int> indices);

            Tenser<T>& operator=(Tenser<T>& other);

            Tenser<T>* merge(const Tenser<T>& other, std::function<T(T, T)> operation);
            Tenser<T>* operator+(Tenser<T> other);
            Tenser<T>* operator-(Tenser<T> other);
            Tenser<T>* operator*(Tenser<T> other);
            Tenser<T>* operator/(Tenser<T> other);

            void replace(std::initializer_list<int> indices, T value);



            // Tenser<T>* operator+(T scalar);
            // Tenser<T>* operator-(T scalar);
            // Tenser<T>* operator*(T scalar);
            // Tenser<T>* operator/(T scalar);

            // Tenser<T>& operator+=(const Tenser<T>& other);
            // Tenser<T>& operator-=(const Tenser<T>& other);
            // Tenser<T>& operator*=(const Tenser<T>& other);
            // Tenser<T>& operator/=(const Tenser<T>& other);
    };

    //template <class T>
    // class Tenser1D : public Tenser<T>{
    //     public:
    //         Tenser1D(int width) : Tenser<T>({width}){}
    //         Tenser1D(const Tenser1D *other) : Tenser<T>(other){}
    //         ~Tenser1D(){}

    //         using Tenser<T>::size;
    //         using Tenser<T>::shape;
    //         using Tenser<T>::depth;
    //         using Tenser<T>::print;
    //         using Tenser<T>::merge;
    //         using Tenser<T>::for_each;
    //         using Tenser<T>::operator[];
    //         using Tenser<T>::operator=;
    //         using Tenser<T>::operator+;
    //         using Tenser<T>::operator-;
    //         using Tenser<T>::operator*;
    //         using Tenser<T>::operator/;
    // };

    // template <class T>
    // class Tenser2D : public Tenser<T>{
    //     public:
    //         Tenser2D(int width, int height) : Tenser<T>({width, height}){}
    //         Tenser2D(const Tenser2D *other) : Tenser<T>(other){}
    //         ~Tenser2D(){}

    //         using Tenser<T>::size;
    //         using Tenser<T>::shape;
    //         using Tenser<T>::depth;
    //         using Tenser<T>::print;
    //         using Tenser<T>::merge;
    //         using Tenser<T>::for_each;
    //         using Tenser<T>::operator[];
    //         using Tenser<T>::operator=;
    //         using Tenser<T>::operator+;
    //         using Tenser<T>::operator-;
    //         using Tenser<T>::operator*;
    //         using Tenser<T>::operator/;
    // };

    // template <class T>
    // class Tenser3D : public Tenser<T>{
    //     public:
    //         Tenser3D(int width, int height, int depth) : Tenser<T>({width, height, depth}){}
    //         Tenser3D(const Tenser3D *other) : Tenser<T>(other){}
    //         ~Tenser3D(){}
    //         using Tenser<T>::size;
    //         using Tenser<T>::shape;
    //         using Tenser<T>::depth;
    //         using Tenser<T>::print;
    //         using Tenser<T>::merge;
    //         using Tenser<T>::for_each;
    //         using Tenser<T>::operator[];
    //         using Tenser<T>::operator=;
    //         using Tenser<T>::operator+;
    //         using Tenser<T>::operator-;
    //         using Tenser<T>::operator*;
    //         using Tenser<T>::operator/;
    // };
    
}

















#endif // TENSER_HPP