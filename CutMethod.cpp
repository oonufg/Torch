#include <iostream>
#include <cmath>

double EPS = 1e-16;
int MAX_ITERATIONS = 1000;
double initial_X1 = 8.0;
double initial_X2 = 3.0;

double fx(double x){
    return x*x*x - 18*x - 83;
}

double secantMethod(double x_1, double x_2){
    int current_iteration = 0;
    double x_3 = 0; 
    if(std::abs(fx(x_2) - fx(x_1)) < EPS){
        return -1;
    }
    while(std::abs(x_2 - x_1) > EPS && current_iteration < MAX_ITERATIONS){
        if(std::abs(fx(x_2) - fx(x_1)) >= EPS){
            x_3 = x_1  - ((x_2 - x_1) * fx(x_1)/(fx(x_2) - fx(x_1)));
        }
        x_1 = x_2;
        x_2 = x_3;
        current_iteration++;
    }
    return x_3;
}

int main(){
    double result = secantMethod(initial_X1, initial_X2);
    std::cout << result << '\n';
}
