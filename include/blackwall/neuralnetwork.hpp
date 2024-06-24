#ifndef NERUALNETWORK_HPP
#define NERUALNETWORK_HPP

#include "model.hpp"

namespace BLKW {
    class NerualNetwork : public Model{
        private:
        public:
            void train(Tenser<double> training_set);
            void feed(Tenser<double> input);
            void test(Tenser<double> training_set);
    };
}

#endif // NERUALNETWORK_HPP