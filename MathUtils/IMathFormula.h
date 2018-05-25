#include<vector>
#include<functional>

class IMathFormula {
    public:
        virtual double get_result(double const input) = 0;
};