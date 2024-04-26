#include <iostream>
#include <cmath>
const int N = 50;

double Fx(double x){
    return sin(x) + cos(x);
}

double calculateIntegralRectangleL(double leftLim, double rightLim){
    double cut = (rightLim - leftLim) / N;
    double result = 0;
    while(leftLim < rightLim){
        result += cut * Fx(leftLim);
        leftLim += cut;
    }
    return result;
}

double calculateIntegralRectangleMean(double leftLim, double rightLim){
    double cut = (rightLim - leftLim) / N;
    double result = 0;
    while(leftLim < rightLim){
        result += cut * Fx(leftLim + cut * 0.5);
        leftLim += cut;
    }
    return result;
}

double calculateIntegralRectangleR(double leftLim, double rightLim){
    double cut = (rightLim - leftLim) / N;
    double result = 0;
    while(leftLim < rightLim){
        result += cut * Fx(leftLim + cut);
        leftLim += cut;
    }
    return result;
}

double calculateIntegralTrapezium(double leftLim, double rightLim){
    double cut = (rightLim - leftLim) / N;
    double result = 0;
    while(leftLim < rightLim){
        result += 0.5 * (Fx(leftLim) + Fx(leftLim + cut)) * cut;
        leftLim += cut;
    }
    return result;
}

double calculateIntegralSimpson(double leftLim, double rightLim){
    double cut = (rightLim - leftLim) / N;
    double result = (Fx(leftLim) + Fx(rightLim)) * 0.5;
    double x1 = leftLim + cut;

    while(x1 < rightLim){
        result += Fx(x1);
        x1 += cut;
    }
    result *= cut;
    return result;
}

int main(){
    double leftLim = -M_PI;
    double rightLim = M_PI;
    std::cout << "Метод прямоугольников левый: " << calculateIntegralRectangleL(leftLim, rightLim) << '\n';
    std::cout << "Метод прямоугольников cредний: " << calculateIntegralRectangleMean(leftLim, rightLim) << '\n';
    std::cout << "Метод прямоугольников правый: " << calculateIntegralRectangleR(leftLim, rightLim) << '\n';
    std::cout << "Метод трапеций: " << calculateIntegralTrapezium(leftLim, rightLim) << '\n';
    std::cout << "Метод симпсона: " << calculateIntegralSimpson(leftLim, rightLim) << '\n';
    std::cout << "Точное значение: " << sin(rightLim) - sin(leftLim) + cos(leftLim) - cos(rightLim) << '\n';
}