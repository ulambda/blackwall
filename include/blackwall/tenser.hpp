#ifndef TENSER_HPP
#define TENSER_HPP

#include <vector>
#include <initializer_list> // Add this line
#include <random> // Add this line
#include <variant>

namespace BLKW{
    template <class T>
    class Tenser{
        private:
            int dimensions[3];
            std::vector<T> data;
        public:
            Tenser();
            Tenser(std::initializer_list<int> dimensions);
            Tenser(const Tenser *other);
            
            static Tenser zeros(std::initializer_list<int> dimensions); 
            static Tenser ones(std::initializer_list<int> dimensions);
            static Tenser random(std::initializer_list<int> dimensions);
    };
}

















#endif // TENSER_HPP