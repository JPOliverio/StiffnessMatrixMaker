#include "vector"
#include <cmath>
using namespace std;


class FrameElement{
    protected:
    //local stiffness matrix
    vector<vector<double>> sm;
    //tranformation matrix
    vector<vector<double>> tr = vector<vector<double>>(6, vector<double>(6, 0.0));
   
    public:

    void framElement(double angle){
        angle = 0;

        tr[0] = {cos(angle), sin(angle), 0, 0, 0, 0};
        tr[1] = {-sin(angle), cos(angle), 0, 0, 0, 0};
        tr[2] = {0, 0, 1, 0, 0, 0};
        tr[3] = {0, 0, 0, cos(angle), sin(angle), 0};
        tr[4] = {0, 0, 0, -sin(angle), cos(angle), 0};
        tr[5] = {0, 0, 0, 0, 0, 1};







     //{-sin(angle), cos(angle), 0, 0, 0, 0};

    }
};