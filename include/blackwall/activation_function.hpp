#ifndef ACTFUN_HPP
#define ACTFUN_HPP

#include <cmath>

namespace BLKW{
    static double sigmoid(double z){
        return 1.0 / (1.0 + std::exp(-z));
    }

    static double identity(double z){
        return z;
    }
}

#endif //ACTFUN_HPP