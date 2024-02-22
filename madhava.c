#include "mathlib.h"

//Variable for keeping track of count of iterations used for estimation
//Count starts at 1 since we already have our first iteration value to start with
static int count = 1;

//Function to estimate pi using the Madhava series
double pi_madhava(void) {

    //Used to keep track of power
    double pows = 1.0;

    //Keeps track of numerator
    double v = 1.0;

    //Keeps track of previous iteration
    double prev = 0.0;

    //Keeps track of answer in current iteration
    double ans = 1.0;

    //Loop and estimate
    for (double i = 1.0; absolute(prev - ans) > (EPSILON); i++) {
        prev = ans;
        count++;
        pows *= (-3.0);
        v = 1.0 / pows;
        ans += v / ((2.0 * i) + 1.0);
    }

    //After breaking out of loop, multiply received value by rad 12
    ans = ans * sqrt_newton(12);

    //Return the estimate of pi calculated
    return ans;
}

//Function to return the amount of iterations used for estimation
int pi_madhava_terms(void) {
    return count;
}
