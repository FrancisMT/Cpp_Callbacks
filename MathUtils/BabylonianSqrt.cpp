#include<assert.h>
#include<cmath>

#include"BabylonianSqrt.h"

BblSqrt::BblSqrt(long max_error) 
    : _max_error_val(max_error) {}

void BblSqrt::add_callback(callback const& cb) {
    _status_check_callbacks.push_back(std::move(cb));
}

double BblSqrt::get_result(double const input) {

    // Error check
    assert(input > 0.f);

    // Calculation iteration number.
    size_t calc_iteration = 0;

    // Set initial guess
    double guess = input;

    while(std::fabs(guess - input/guess) > _max_error_val) {

        // Invoke Callbacks
        for(const auto & callback : _status_check_callbacks){
            callback(calc_iteration, guess);
        }

        guess = (guess + (input/guess) ) / 2.f;
        ++calc_iteration; 
    }

    return guess;
}