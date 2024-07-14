#ifndef LOSSFUN_HPP
#define LOSSFUN_HPP

#include <cmath>
#include <vector>

namespace BLKW{
    class LossFunction{
        public:

            /**
             * @brief calculates the mean squared error between the predicted values and the actual values
             * @param y the predicted values
             * @param t the actual values
             * @param size the number of values in the arrays
             * @return the mean squared error
             */
            const static double mean_squared_error(double* y, double* t, int size);

            /**
             * @bref calculates the mean squared error between the predicted values and the actual values
             * @param y the predicted values
             * @param t the actual values
             * @return the mean squared error
             * @note the size of the arrays must be the same
             */
            const static double mean_squared_error(std::vector<double> y, std::vector<double> t);

            /**
             * @brief calculates the cross entropy loss between the predicted values and the actual values
             * @param y the predicted values
             * @param t the actual values
             * @param size the number of values in the arrays
             * @return the cross entropy loss
             */
            const static double cross_entropy(double* y, double* t, int size);

            /**
             * @brief calculates the cross entropy loss between the predicted values and the actual values
             * @param y the predicted values
             * @param t the actual values
             * @return the cross entropy loss
             * @note the size of the arrays must be the same
             */
            const static double cross_entropy(std::vector<double> y, std::vector<double> t);
    };
}

#endif //LOSSFUN_HPP