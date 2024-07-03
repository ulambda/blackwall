#ifndef LOSSFUN_HPP
#define LOSSFUN_HPP

#include <cmath>

namespace BLKW{
    class LossFunction{
        public:
            const static double mean_squared_error(double* y_true, double* y_pred, int size);
            const static double cross_entropy(double* y_true, double* y_pred, int size);
    };
}

#endif //LOSSFUN_HPP