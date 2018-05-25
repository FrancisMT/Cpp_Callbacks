#include<iostream>

/**
* Callbacks signature:
* void (size_t, double)
*/
namespace BblSqrtCallbacks {

    void FunctionPointerCallback(size_t const iteration, double const guess) {
        std::cout << iteration << " : " << guess << " (Function Pointer)" << std::endl;
    }

    class MemberFunctionCallback {
        public:
            void Call(size_t const iteration, double const guess){
                std::cout << iteration << " : " << guess << " (Member Function)" << std::endl;
            }
    };

    class FunctorCallback {
        void operator()(size_t const iteration, double const guess) {
            std::cout << iteration << " : " << guess << " (Functor)" << std::endl;
        }
    };

    auto LambdaCallback = [](size_t const iteration, double const guess){
        std::cout << iteration << " : " << guess << " (Lambda)" << std::endl;
    };
}