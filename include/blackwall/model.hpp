#ifndef MODEL_HPP
#define MODEL_HPP

#include "tenser.hpp"

namespace BLKW {
    /**
     * Abstract class for all machine learning models
     */
    class Model{
        public:
            /**
             * @brief trains model on an training set
             * @param training_set the training set to train the model on
             */
            virtual void train(const Tenser<double>& trainset) = 0;
            /**
             * @brief forward feeds an input through the model and returns the output
             * @param input the input to feed through the model
             */
            virtual Tenser<double> feed(const Tenser<double>& input) = 0; 
            /**
             * @brief tests the accuracy of the model by comparing the output of the model on a given test point to the exepcted output and returns the accuracy
             * @param testset the test set to test the model on
             */
            virtual double test(const Tenser<double>& testset) = 0;
        protected:
    };
}
#endif // MODEL_HPP