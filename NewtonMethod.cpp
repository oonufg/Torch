#include <iostream>
#include <cmath>
double eps = 1e-16;
double initial = -50.0;
int interation = 0;
int maxIter = 100;
double Fx(double x){
    return x*sin(x) + 5;
}

double dFx(double x){
    return sin(x) + x*cos(x);
}



int main(){
    double x1 = initial - Fx(initial)/dFx(initial);
    while(std::abs(Fx(x1)) > eps && interation < maxIter){
        x1 = x1 - Fx(x1)/dFx(x1);
        interation++;
    }
    std::cout << x1 << '\n';
    std::cout << interation;
}