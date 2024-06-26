#ifndef MODEL_HPP
#define MODEL_HPP

#include "tenser.hpp"

namespace BLKW {
    /**
     * @brief Abstract class for machine learning models
     */
    class Model{
        public:
            virtual void train(const Tenser<double>& training_set) = 0; //trains the model on the inputed test set
            virtual Tenser<double> feed(const Tenser<double>& input) = 0; //accepts a data instances and produces an output using the model
            virtual void test(const Tenser<double>& training_set) = 0; //tests the accuracy of the model using a test set
        protected:
    };
}
#endif // MODEL_HPP