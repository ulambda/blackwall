#ifndef LOSSFUN_HPP
#define LOSSFUN_HPP

#include <cmath>
#include <vector>

namespace BLKW{
    class LossFunction{
        public:

            /**
             * @brief enum class for the different types of loss functions
             */

            enum class Type{
                MEAN_SQUARED_ERROR,
                CROSS_ENTROPY
            };

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
            const static double mean_squared_error(const std::vector<double>& y, const std::vector<double>& t);

            /**
             * @brief calculates the derivative of the mean squared error loss function
             * @param y the predicted values
             * @param t the actual values
             * @param size the number of values in the arrays
             * @return the derivative of the mean squared error loss function
             */

            const static double* mean_squared_error_derivative(double* y, double* t, int size);

            /**
             * @brief calculates the derivative of the mean squared error loss function
             * @param y the predicted values
             * @param t the actual values
             * @return the derivative of the mean squared error loss function
             * @note the size of the arrays must be the same
             */

            const static std::vector<double> mean_squared_error_derivative(const std::vector<double>& y, const std::vector<double>& t);

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

            /**
             * @brief calculates the derivative of the cross entropy loss function
             * @param y the predicted values
             * @param t the actual values
             * @param size the number of values in the arrays
             * @return the derivative of the cross entropy loss function
             */

            const static double* cross_entropy_derivative(double* y, double* t, int size);

            /**
             * @brief calculates the derivative of the cross entropy loss function
             * @param y the predicted values
             * @param t the actual values
             * @return the derivative of the cross entropy loss function
             * @note the size of the arrays must be the same
             */

            const static std::vector<double> cross_entropy_derivative(const std::vector<double>& y, const std::vector<double>& t);
    };
}

#endif //LOSSFUN_HPP