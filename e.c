#include "mathlib.h"

//Keep track of iterations needed for estimation
static int count = 0;

//Function to return estimate of euler's value
double e(void) {

    //Variable to keep track of factorial values
    double factorial = 1.0;

    //Variable to keep track of estimation at previous iteration
    double prev = -1.0;

    //Variable to keep track of the current estimation
    double ans = 0.0;

    //Loop to estimate e
    for (double i = 1.0; absolute(ans - prev) > EPSILON; i++) {
        prev = ans;
        count++;
        ans += 1.0 / factorial;
        factorial *= i;
    }

    //Return answer once loop is exited
    return ans;
}

//Function to return count of iterations
int e_terms(void) {
    return count;
}
