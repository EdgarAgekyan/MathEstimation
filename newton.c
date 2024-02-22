#include "mathlib.h"

//Variable to keep track of iterations used for estimation
static int count = 0;

//Function to estimate square root
double sqrt_newton(double x) {

    //Variable to keep track of estimate at previous iteration
    double prev = 0.0;

    //Variable to keep track of current estimation
    double ans = 1.0;

    //Loop to estimate the square root of "x"
    while (absolute(ans - prev) > EPSILON) {
        count++;
        prev = ans;
        ans = 0.5 * (prev + x / ans);
    }

    //After we break out of the loop, we return the estimation
    return ans;
}

//Function to return the number of iterations used for the estimation of the square root
int sqrt_newton_iters(void) {
    return count;
}
