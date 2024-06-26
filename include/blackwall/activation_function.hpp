#ifndef ACTFUN_HPP
#define ACTFUN_HPP

#include <cmath>

namespace BLKW{
    class ActivationFunction{
        public:
            /**
             * @brief just returns the input value
             * use this when you don't want to use an activation function
             * c++ compiler will optimize it out
             */
            static const double identity(double x);
            /**
             * @brief maps the input to a value between 0 and 1
             */
            static const double sigmoid(double x);
            /**
             * @brief maps the input to a value between -1 and 1
             */
            static const double tanh(double x);
            
            /**
             * @brief returns input if its positive, else returns 0
             */
            static const double relu(double x);

            /**
             * @brief maps the input to a probability distribution over a set of possible outcomes
             */
            static const double softmax(double x);

            /**
             * @brief returns 1 if input is positive, else returns 0
             */
            static const double step(double x);
    };
}

#endif //ACTFUN_HPP