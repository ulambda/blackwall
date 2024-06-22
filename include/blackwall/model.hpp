#ifndef MODEL_HPP
#define MODEL_HPP

namespace BLKW {
    /**
     * Model is an abstract type that defines the structure that all machine learning models must abide by.
     * All models must provide an implemenation for train, test and feed as the baseline standard.
     */
    class Model{
        public:
            virtual void train() = 0; //trains the model on the inputed test set
            virtual void feed() = 0; //accepts a data instances and produces an output using the model
            virtual void test() = 0; //tests the accuracy of the model using a test set
        protected:

    };

}
















#endif // MODEL_HPP