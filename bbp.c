#include "mathlib.h"

//Variable to keep track of iterations used for estimation
//Count starts at 1 since the first value of the series is calculated.
static int count = 1;

//Function that implements the bbp formula to estimate pi
double pi_bbp(void) {

    //This variable helps keep track of values when using exponents
    double pows = 1.0;

    //Keeps track of estimation in previous iteration
    double prev = 0.0;

    //This variable is the estimation we return.
    //It starts already with the first iteration value completed
    double ans = 47.0 / 15.0;

    //These temporary values are used to help with implementing the math of bbp.
    double temp = 0.0;
    double temp2 = 0.0;
    for (double i = 1.0; absolute(ans - prev); i++) {
        count++;
        prev = ans;
        pows *= 16.0;
        temp = 0.0;
        temp = 1.0 / pows;
        temp2 = (((4.0 / (8.0 * i + 1.0)) - (2.0 / (8.0 * i + 4.0)) - (1.0 / (8.0 * i + 5.0))
                  - (1.0 / (8.0 * i + 6.0))));

        ans += temp * temp2;
    }
    return ans;
}

int pi_bbp_terms(void) {
    return count;
}
