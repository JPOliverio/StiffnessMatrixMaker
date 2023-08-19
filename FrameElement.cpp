#include "vector"
#include <cmath>

using namespace std;


class FrameElement{
    protected:
    //local stiffness matrix
    vector<vector<double>> sm;
    //tranformation matrix
    vector<vector<double>> tr = vector<vector<double>>(6, vector<double>(6, 0.0));
    vector<vector<double>> Transformedsm  = vector<vector<double>>(6, vector<double>(6, 0.0));
    vector<vector<double>> Transformedsm2  = vector<vector<double>>(6, vector<double>(6, 0.0));
   
    public:
    void transformSM(double angle){
        double pi = 3.141592653589793238462643383279502884197169399375105820974944;
        angle = angle*pi/180;
        //to put a local transformation matrix in global coordiants we use the formula K=(T^t)*k+t

        tr[0] = {cos(angle), -sin(angle), 0, 0, 0, 0};
        tr[1] = {sin(angle), cos(angle), 0, 0, 0, 0};
        tr[2] = {0, 0, 1, 0, 0, 0};
        tr[3] = {0, 0, 0, cos(angle), -sin(angle), 0};
        tr[4] = {0, 0, 0, sin(angle), cos(angle), 0};
        tr[5] = {0, 0, 0, 0, 0, 1};


        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    Transformedsm[i][j] += tr[i][k] * sm[k][j];
                }
            }
        }


        tr[0] = {cos(angle), sin(angle), 0, 0, 0, 0};
        tr[1] = {-sin(angle), cos(angle), 0, 0, 0, 0};
        tr[2] = {0, 0, 1, 0, 0, 0};
        tr[3] = {0, 0, 0, cos(angle), sin(angle), 0};
        tr[4] = {0, 0, 0, -sin(angle), cos(angle), 0};
        tr[5] = {0, 0, 0, 0, 0, 1};

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    Transformedsm2[i][j] += Transformedsm[i][k] * tr[k][j];
                }
            }
        }

        sm = Transformedsm2;
    }

    vector<vector<double>> getStiffMatrix(){
        //return stiffnessMatrix;
        return sm;
    }


};