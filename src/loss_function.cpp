#include "../include/blackwall/loss_function.hpp"

namespace BLKW{
    const double LossFunction::mean_squared_error(double* y_true, double* y_pred, int size){
        double sum = 0;
        for(int i = 0 ; i < size ; i++){
            sum += pow(y_true[i] - y_pred[i], 2);
        }
        return sum / size;
    }

    const double LossFunction::cross_entropy(double* y_true, double* y_pred, int size){
        double sum = 0;
        for(int i = 0 ; i < size ; i++){
            sum += y_true[i] * log(y_pred[i]);
        }
        return -sum;
    }
}