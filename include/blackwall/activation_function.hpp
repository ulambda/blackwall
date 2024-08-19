#ifndef ACTFUN_HPP
#define ACTFUN_HPP

#include <cmath>

namespace BLKW{
    class ActivationFunction{
        public:
            /**
             * @brief enum class for the different types of activation functions
             */
            enum class Type{
                IDENTITY,
                SIGMOID,
                TANH,
                RELU,
                SOFTMAX,
                STEP
            };

            /**
             * @brief returns the activation function based on the type
             * @param type the type of activation function
             * @return pointer to the activation function
             */
            static const double (*get_activation_function(Type type))(double);

            /**
             * @brief returns the derivative of the activation function based on the type
             * @param type the type of activation function
             * @return pointer to the derivative of the activation function
             */
            static const double (*get_activation_function_derivative(Type type))(double);
            
            /**
             * @brief just returns the input value
             * use this when you don't want to use an activation function
             * c++ compiler will optimize it out
             */
            static const double identity(double x);

            /**
             * @brief derivative of the identity function is always 1
             */
            static const double identity_derivative(double x);

            /**
             * @brief maps the input to a value between 0 and 1
             */
            static const double sigmoid(double x);

            /**
             * @brief derivative of the sigmoid function
             */

            static const double sigmoid_derivative(double x);

            /**
             * @brief maps the input to a value between -1 and 1
             */
            static const double tanh(double x);

            /**
             * @brief derivative of the tanh function
             */
            static const double tanh_derivative(double x);
            
            /**
             * @brief returns input if its positive, else returns 0
             */
            static const double relu(double x);

            /**
             * @brief derivative of the relu function
             */
            static const double relu_derivative(double x);

            /**
             * @brief maps the input to a probability distribution over a set of possible outcomes
             */
            static const double softmax(double x);

            /**
             * @brief derivative of the softmax function
             */

            static const double softmax_derivative(double x);

            /**
             * @brief returns 1 if input is positive, else returns 0
             */
            static const double step(double x);

            /**
             * @brief derivative of the step function
             */
            static const double step_derivative(double x);
    };
}

#endif //ACTFUN_HPP