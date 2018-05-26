
#include"MathUtils/BabylonianSqrt.h"
#include"MathUtils/BabylonianSqrtCallbacks.h"

int main() {

    BblSqrt calc_bblsqrt(1e-6);

    // Function Pointer
    {
        auto * const ft_cb = BblSqrtCallbacks::FunctionPointerCallback; 
        calc_bblsqrt.add_callback(ft_cb);

        // Alternative syntax
        // calc_bblsqrt.add_callback(&BblSqrtCallbacks::FunctionPointerCallback);
    }

    // Member Function
    {
        BblSqrtCallbacks::MemberFunctionCallback mb_cb_obj;

        // This type of callback uses an invisible first argument:
        //a pointer (*this) to an instance of the class.
        // hence the use of std::bind to surpass this.
        auto mb_cb = std::bind
            (
                &BblSqrtCallbacks::MemberFunctionCallback::Call,    // Function
                &mb_cb_obj,                                         // First argument (*this)
                std::placeholders::_1,                              // First placeholder
                std::placeholders::_2                               // Second placeholder
            );

        calc_bblsqrt.add_callback(mb_cb);
    }

    //Functor
    {
        BblSqrtCallbacks::FunctorCallback fct_cb;
        calc_bblsqrt.add_callback(fct_cb);

        // Alternative syntax
        // calc_bblsqrt.add_callback(BblSqrtCallbacks::FunctorCallback());
    }

    //Lambda
    {
        calc_bblsqrt.add_callback(BblSqrtCallbacks::LambdaCallback);
    }

    std::cout << "Square Root Value = " << calc_bblsqrt.get_result(1234.5*1234.5) << std::endl;
    return 0;
}