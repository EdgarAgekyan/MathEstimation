#include "mathlib.h"

//Keep track of iterations used for our approximation
static int iteration_count = 0;

//Function that returns double value that is an estimation of pi
double pi_euler(void) {

    //Keep track of the value estimated in the previous estimation
    double previous_iteration_value = -1.0;

    //The current estimation/answer to return
    double answer = 0.0;

    //Loop until the absolute value of the difference between our
    //previous and current answer is less than EPSILON

    for (double i = 1.0; absolute(answer - previous_iteration_value) > EPSILON; i++) {
        //Store the current iteration value in the previous variable
        previous_iteration_value = answer;
        //Calculate the estimation
        answer += (1.0 / (i * i));
        //Increment our iteration ocunt
        iteration_count++;
    }

    //Multiply the estimation received from the summation by 6
    //Then take the square root of this and receive the final estimation
    answer = sqrt_newton(6.0 * answer);

    //Return the final estimation
    return answer;
}

//Function to return the amount of iterations used to estimate
int pi_euler_terms(void) {
    return iteration_count;
}
