#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#define OPTIONS "aebmrvnhs"

int main(int argc, char **argv) {
    int opt = 0;

    //Keeps track of terms being returned from functions
    int terms = 0;

    //Keeps track of what inputs the user has specified
    int case_a = 0;
    int case_e = 0;
    int case_b = 0;
    int case_r = 0;
    int case_m = 0;
    int case_v = 0;
    int case_n = 0;
    int case_s = 0;
    int case_h = 0;
    int case_i = 0;

    //Make variables that keep track of the math.h library estimations
    double math_e = exp(1);
    double math_pi = M_PI;
    double math_sqrt;

    //Variable to keep track of difference between my function estimations and the math.h library estimations
    double difference;

    //Variables to keep track of function estimations
    double func_e = e();
    double func_e_terms = e_terms();
    double func_b = pi_bbp();
    double func_b_terms = pi_bbp_terms();
    double func_m = pi_madhava();
    double func_m_terms = pi_madhava_terms();

    double func_eu = pi_euler();
    double func_eu_terms = pi_euler_terms();

    double func_v = pi_viete();
    double func_v_terms = pi_viete_factors();
    double func_n = 0.0;

    //If there are no inputs, we just print out the menu.
    //We make the case_h, which is used for menu printing, equal to 1 or true
    if (argc == 1) {
        case_h = 1;
    }

    //Gets the user inputs
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': case_a = 1; break;
        case 'e': case_e = 1; break;
        case 'b': case_b = 1; break;
        case 'm': case_m = 1; break;
        case 'r': case_r = 1; break;
        case 'v': case_v = 1; break;
        case 'n': case_n = 1; break;
        case 's': case_s = 1; break;
        case 'h': case_h = 1; break;
        default: printf("invalid option == '%x'", opt); return 0;
        }
    }

    //After all the inputs are gathered, these if statements execute if they are according to what the user specified.
    if (case_a) {
        case_e = 1;
        case_b = 1;
        case_m = 1;
        case_r = 1;
        case_v = 1;
        case_n = 1;
    }
    if (case_e) {
        difference = absolute(func_e - math_e);
        printf("e() = %0.15f M_E = %0.15f diff = %0.15f\n", func_e, math_e, difference);
        terms = func_e_terms;
        if (case_s == 1) {
            printf("e() terms = %d\n", terms);
        }
    }
    if (case_b) {
        difference = absolute(func_b - math_pi);
        printf("pi_bbp() = %0.15f M_PI = %0.15f diff = %0.15f\n", func_b, math_pi, difference);
        terms = func_b_terms;
        if (case_s == 1) {
            printf("pi_bbp() terms = %d\n", terms);
        }
    }
    if (case_m) {
        difference = absolute(func_m - math_pi);
        printf("pi_madhava() = %0.15f M_PI = %0.15f diff = %0.15f\n", func_m, math_pi, difference);
        terms = func_m_terms;
        if (case_s == 1) {
            printf("pi_madhava() terms = %d\n", terms);
        }
    }
    if (case_r) {
        difference = absolute(func_eu - math_pi);
        printf("pi_euler() = %0.15f M_PI = %0.15f diff = %0.15f\n", func_eu, math_pi, difference);
        terms = func_eu_terms;
        if (case_s == 1) {
            printf("pi_euler() terms = %d\n", terms);
        }
    }
    if (case_v) {
        difference = absolute(func_v - math_pi);
        printf("pi_viete() = %0.15f M_PI = %0.15f diff = %0.15f\n", func_v, math_pi, difference);
        terms = func_v_terms;
        if (case_s == 1) {
            printf("pi_viete() terms = %d\n", terms);
        }
    }
    if (case_n) {
        for (double i = 0.0; i <= 10.0; i += 0.1) {
            func_n = sqrt_newton(i);
            math_sqrt = sqrt(i);
            difference = absolute(func_n - math_sqrt);
            printf("sqrt_newton(%0.6f) = %0.15f, sqrt(%0.6f) = %0.15f, diff = %0.15f\n", i, func_n,
                i, math_sqrt, difference);
            terms = sqrt_newton_iters();
            if (case_s == 1) {
                printf("sqrt_newton() terms = %d\n", terms);
            }
        }
    }
    if (case_h) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\n");
        printf("USAGE\n   ./mathlib-test [-aebmrvnsh]\n\n");
        printf("OPTIONS\n");
        printf("  -a   Runs all tests.\n");
        printf("  -e   Runs e test.\n");
        printf("  -b   Runs BBP pi test.\n");
        printf("  -m   Runs Madhava pi test.\n");
        printf("  -r   Runs Euler pi test.\n");
        printf("  -v   Runs Viete pi test.\n");
        printf("  -n   Runs Newton square root tests.\n");
        printf("  -s   Print verbose statistics.\n");
        printf("  -h   Display program synopsis and usage.\n");
    }

    return 0;
}
