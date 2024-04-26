#include <iostream>

const double EPS = 0.e-16;
const int MAX_ITERATIONS = 1000;

double fx(double x){
    return x*x*x + 2*x*x + 0.5*x + 1;
}

double lambdaFn(double a, double b){
    return (fx(b) - fx(a)) / (b - a);
}

double simpleIterations(double a, double b){
    double x_0 = (b - a) / 2;
    double x_1;
    double lambdaValue = lambdaFn(a, b);
    if (fx(a) - fx(b) == 0){
        std::cout << "Zero Divide" << '\n';
        return 0;
    }

    int currentIteration = 0;
    while(fx(a)*fx(b) <= EPS && currentIteration < MAX_ITERATIONS){
        currentIteration++;

        x_1 = x_0 - fx(x_0) / lambdaValue;
        if(std::abs(x_0 - x_1) <= EPS){
            return x_1;
        }
        x_0 = x_1;
    }
    return x_0;
}

int main(){
    double InitialA = -10;
    double InitialB = 0;
    std::cout << simpleIterations(InitialA, InitialB) << '\n';
}