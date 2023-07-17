#include <iostream>
#include "RecBeamStiffMatrix.cpp"
#include <list>
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
        double y=3e4;
        RecBeamStiffMatrix sm = RecBeamStiffMatrix(l, h, w, y);

       vector<vector<double>> elementSM =sm.getStiffMatrix();
       
       //(4, vector<double>(4, 0.0));
       sm.printStiffnessMatrix();

    list<BeamElement> trusElements;

    RecBeamStiffMatrix e1 = RecBeamStiffMatrix(20, .417, .417, y);
    RecBeamStiffMatrix e2 = RecBeamStiffMatrix(16, .417, .417, y);
    RecBeamStiffMatrix e3 = RecBeamStiffMatrix(12, .417, .417, y);
    RecBeamStiffMatrix e4 = RecBeamStiffMatrix(16, .417, .417, y);
    RecBeamStiffMatrix e5 = RecBeamStiffMatrix(20, .417, .417, y);
    RecBeamStiffMatrix e6 = RecBeamStiffMatrix(20, .417, .417, y);
    RecBeamStiffMatrix e7 = RecBeamStiffMatrix(16, .417, .417, y);
    RecBeamStiffMatrix e8 = RecBeamStiffMatrix(12, .417, .417, y);

    double e1Degree = 36.87;
    double e2Degree = 0.0;
    double e3Degree = 90.0;
    double e4Degree = 0.0;
    double e5Degree = 143.13;
    double e6Degree = 36.87;
    double e7Degree = 0.0;
    double e8Degree = 90.0;



    e1.transformSM(e1Degree);
    e2.transformSM(e2Degree);
    e3.transformSM(e3Degree);
    e4.transformSM(e4Degree);
    e5.transformSM(e5Degree);
    e6.transformSM(e6Degree);
    e7.transformSM(e7Degree);
    e8.transformSM(e8Degree);

    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();

    trusElements.push_back(e1);
    trusElements.push_back(e2);
    trusElements.push_back(e3);







    //BeamTransformationMatrix e1TranSM = calculateBeamTransformationMatrix()

    return 0;
}