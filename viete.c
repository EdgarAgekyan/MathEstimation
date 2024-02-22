#include "mathlib.h"

//Variable to keep track of iterations used to estimate value
static int count = 0;

//Function to estimate pi using Viete's formula
double pi_viete(void) {

    //Variable to keep track of previous variable
    double prev = 0.0;

    //Variable to keep track of answer, we start with the first iteration
    double ans = sqrt_newton(2.0) / 2.0;

    //Temporary variable to help with calculations
    double temp = sqrt_newton(2.0);

    //Loop to calculate the approximation of the square root of x
    while (absolute(ans - prev)) {
        prev = ans;
        count++;
        temp += 2;
        temp = sqrt_newton(temp);
        ans *= (temp / 2);
    }
    //Divide 2 by the estimatied value received by the loop to receive the pi estimation
    ans = 2.0 / ans;

    //Return the pi estimation
    return ans;
}

//Function to return the count of iterations it took to estimate pi
int pi_viete_factors(void) {
    return count;
} 
