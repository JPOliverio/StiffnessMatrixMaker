#include <iostream>
#include "RecBeamStiffMatrix.cpp"
using namespace std;

int main(){
/*
        double** stiffnessMatrix = new double*[4];
    for (int i = 0; i < 4; ++i){
        stiffnessMatrix[i] = new double[4];
    }
    */

        double l=10;
        double h=.2;
        double w=.1;
        double y=200e9;
        RecBeamStiffMatrix sm = RecBeamStiffMatrix(l, h, w, y);

       vector<vector<double>> elementSM =sm.getStiffMatrix();
       
       //(4, vector<double>(4, 0.0));
       sm.printStiffnessMatrix();

    RecBeamStiffMatrix e1 = RecBeamStiffMatrix(10, .2, .1, y);
    RecBeamStiffMatrix e2 = RecBeamStiffMatrix(5, .2, .1, y);
    RecBeamStiffMatrix e3 = RecBeamStiffMatrix(8, .2, .1, y);

    double e1Degree = 0.0;
    double e2Degree = 30.0;
    double e3Degree = 45.0;

    e1.transformSM(e1Degree);
    e2.transformSM(e2Degree);
    e3.transformSM(e3Degree);

    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();


    //BeamTransformationMatrix e1TranSM = calculateBeamTransformationMatrix()

    return 0;
}