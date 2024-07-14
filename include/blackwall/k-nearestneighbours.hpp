#ifndef K_NEARESTNEIGHBOURS_HPP
#define K_NEARESTNEIGHBOURS_HPP

#include "model.hpp"
#include <vector>

namespace BLKW{
    class KNearestNeighbours : public Model{
        private:
            int k;
            std::vector<std::vector<double>> data;
            std::vector<int> labels;
            
        public:
            KNearestNeighbours(int k);
            
            void train(std::vector<std::vector<double>> data, std::vector<int> labels);
            std::vector<int> predict(std::vector<std::vector<double>> data);

            void train(const Tenser<double>& trainset);
            Tenser<double> feed(const Tenser<double>& input);
            double test(const Tenser<double>& testset);

    };
}

#endif // K_NEARESTNEIGHBOURS_HPP