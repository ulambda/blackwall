#ifndef TENSER_HPP
#define TENSER_HPP

#include <vector>
#include <initializer_list>
#include <random> 
#include <numeric>
#include <variant>
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
            
            // using NestedInit = std::variant<T, std::initializer_list<NestedInit>>;
            // Tenser(NestedInit values){
            // }

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
}

#endif // TENSER_HPP