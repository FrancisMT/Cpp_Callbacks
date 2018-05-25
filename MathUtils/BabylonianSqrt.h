#include"IMathFormula.h"
#include<vector>
#include<functional>

class BblSqrt : public IMathFormula {

    public:

        // Callback alias
        using callback = std::function<void(size_t const iteration, double const guess)>;

        // Callback vector alias
        using callbackvector = std::vector<callback>;

        BblSqrt(long max_error);
        ~BblSqrt() = default;

        void add_callback(callback const& cb);
        virtual double get_result(double const input) override;

    private:

        // Maximum allowed error.
        long _max_error_val;

        //Callback vector used to inform the user of the state of the math operation
        callbackvector _status_check_callbacks;
};