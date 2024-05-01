#include <iostream>
#include <cmath>

double EPS = 0.00001;
const int N = 10;

double fx(double x){
    return sin(x) + cos(x);
};

double simpsonsFormula(double a, double b){
    double result = fx(a) + fx(b);
    double h = (b - a) / N;
    for (int i = 1; i < N ; i++){
        if(i % 2 == 0){
            result += 2 * fx(a + i * h);
        } else {
            result += 4 * fx(a + i * h);
        }
    }
    result *= h / 3;
    return result;
}

double calculateIntegralAdaptive(double leftLim, double rightLim, double eps){
    double result = 0;
    double middle = (rightLim + leftLim) / 2;

    if (std::abs(leftLim - rightLim) < EPS){
        return 0;
    }

    double teta = std::abs(simpsonsFormula(leftLim, middle) + simpsonsFormula(middle, rightLim) - simpsonsFormula(leftLim, rightLim)) / 15;
    if(teta > EPS){
        result += calculateIntegralAdaptive(leftLim, middle, eps / 2) + calculateIntegralAdaptive(middle, rightLim, eps / 2);
    } else {
        return simpsonsFormula(leftLim, rightLim);
    }
    return result;
}

int main(){
    double ll = -M_PI;
    double rl = M_PI;
    //std::cout << simpsonsFormula(ll, rl) << '\n';
    std::cout << "Adaptive integration " << calculateIntegralAdaptive(ll, rl, EPS) << '\n';
}