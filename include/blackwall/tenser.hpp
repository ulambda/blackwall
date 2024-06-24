#ifndef TENSER_HPP
#define TENSER_HPP

#include <vector>

namespace BLKW{
    template <class T>
    class Tenser{
        private:
            int dimensions[];
            std::vector<T> data;
        
            
        public:
            Tenser();
            Tenser(const Tenser *other); //copy constructor
            
            static Tenser zeros(int dimensions[]); 
            static Tenser ones(int dimensions[]);





            


    };
}

















#endif // TENSER_HPP