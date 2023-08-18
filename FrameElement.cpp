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
   
    public:
    void transformSM(double angle){
        //angle = 0;
        //to put a local transformation matrix in global coordiants we use the formula K=(T^t)*k+t

        tr[0] = {cos(angle), -sin(angle), 0, 0, 0, 0};
        tr[1] = {sin(angle), cos(angle), 0, 0, 0, 0};
        tr[2] = {0, 0, 1, 0, 0, 0};
        tr[3] = {0, 0, 0, cos(angle), -sin(angle), 0};
        tr[4] = {0, 0, 0, sin(angle), cos(angle), 0};
        tr[5] = {0, 0, 0, 0, 0, 1};

        for(int j =0; j < 6; j++){
            for(int i = 0; i < 6; i++){
                Transformedsm[j][i] = tr[i][0] * sm[0][j] 
                                            + tr[i][1] * sm[1][j]
                                            + tr[i][2] * sm[2][j]
                                            + tr[i][3] * sm[3][j]
                                            + tr[i][4] * sm[4][j]
                                            + tr[i][5] * sm[5][j];
            }
        }

        tr[0] = {cos(angle), sin(angle), 0, 0, 0, 0};
        tr[1] = {-sin(angle), cos(angle), 0, 0, 0, 0};
        tr[2] = {0, 0, 1, 0, 0, 0};
        tr[3] = {0, 0, 0, cos(angle), sin(angle), 0};
        tr[4] = {0, 0, 0, -sin(angle), cos(angle), 0};
        tr[5] = {0, 0, 0, 0, 0, 1};

        for(int j =0; j < 6; j++){
            for(int i = 0; i < 6; i++){
                Transformedsm[j][i] = Transformedsm[i][0] * tr[0][j] 
                                                + Transformedsm[i][1] * tr[1][j]
                                                + Transformedsm[i][2] * tr[2][j]
                                                + Transformedsm[i][3] * tr[3][j]
                                                + Transformedsm[i][4] * tr[4][j]
                                                + Transformedsm[i][5] * tr[5][j];
            }
        }

        sm = Transformedsm;
    }

    vector<vector<double>> getStiffMatrix(){
        //return stiffnessMatrix;
        return sm;
    }





};