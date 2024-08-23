#include "../include/blackwall/loss_function.hpp"

#include <cmath>
#include <vector>
#include <stdexcept>


namespace BLKW{
    const double LossFunction::mean_squared_error(double* y_true, double* y_pred, int size){
        double sum = 0;
        for(int i = 0 ; i < size ; i++)
            sum += pow(y_true[i] - y_pred[i], 2);
        
        return sum / size;
    }

    const double LossFunction::mean_squared_error(const std::vector<double>& y, const std::vector<double>& t){
        if(y.size() != t.size())
            throw std::invalid_argument("size of y and t must be the same. but got y.size() = " + std::to_string(y.size()) + " and t.size() = " + std::to_string(t.size()));

        double sum = 0;
        for(int i = 0 ; i < y.size() ; i++)
            sum += pow(y[i] - t[i], 2);
        
        return sum / y.size();
    }

    const double LossFunction::cross_entropy(double* y, double* t, int size){
        double sum = 0;
        for(int i = 0 ; i < size ; i++){
            sum += y[i] * log(t[i]);
        }
        return -sum;
    }

    const double LossFunction::cross_entropy(std::vector<double> y, std::vector<double> t){
        if(y.size() != t.size())
            throw std::invalid_argument("the size of y and t must be the same size when calculating the loss");

        double sum = 0;
        for(int i = 0 ; i < y.size() ; i++){
            sum += y[i] * log(t[i]);
        }
        return -sum;
    }

    //dirivatives

    const double* LossFunction::mean_squared_error_derivative(double* y, double* t, int size){
        double* d = new double[size];
        for(int i = 0 ; i < size ; i++)
            d[i] = 2 * (y[i] - t[i]);
        return d;
    }

    const std::vector<double> LossFunction::mean_squared_error_derivative(const std::vector<double>& y, const std::vector<double>& t){
        if(y.size() != t.size())
            throw std::invalid_argument("size of y and t must be the same. but got y.size() = " + std::to_string(y.size()) + " and t.size() = " + std::to_string(t.size()));

        std::vector<double> d(y.size());
        for(int i = 0 ; i < y.size() ; i++)
            d[i] = 2 * (y[i] - t[i]);
        return d;
    }

    const double* LossFunction::cross_entropy_derivative(double* y, double* t, int size){
        double* d = new double[size];
        for(int i = 0 ; i < size ; i++)
            d[i] = -t[i] / y[i];
        return d;
    }

    const std::vector<double> LossFunction::cross_entropy_derivative(const std::vector<double>& y, const std::vector<double>& t){
        if(y.size() != t.size())
            throw std::invalid_argument("size of y and t must be the same. but got y.size() = " + std::to_string(y.size()) + " and t.size() = " + std::to_string(t.size()));

        std::vector<double> d(y.size());
        for(int i = 0 ; i < y.size() ; i++)
            d[i] = -t[i] / y[i];
        return d;
    }




}