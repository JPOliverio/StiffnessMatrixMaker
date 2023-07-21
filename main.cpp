#include <iostream>
#include "RecBeamStiffMatrix.cpp"
#include <list>
//#include "BeamElement.cpp"
#include "TrusGlobalStiffMatrix.cpp"
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
        double y=2e9;

    list<BeamElement> trusElements;


    RecBeamStiffMatrix e1 = RecBeamStiffMatrix(1, .1, .1, y);
    RecBeamStiffMatrix e2 = RecBeamStiffMatrix(1, .1, .1, y);
    RecBeamStiffMatrix e3 = RecBeamStiffMatrix(1, .1, .1, y);
    /*
    conect.addConnectivity(0,1);
    conect.addConnectivity(1,2);
    conect.addConnectivity(0,2);
    */


    double e1Degree = 60.0;
    double e2Degree = 300.0;
    double e3Degree = 0.0;


    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();



    e1.transformSM(e1Degree);
    e2.transformSM(e2Degree);
    e3.transformSM(e3Degree);


    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();



// not sure what this does anymoreor was for.
    trusElements.push_back(e1);
    trusElements.push_back(e2);
    trusElements.push_back(e3);


    TrusGlobalStiffMatrix tb = TrusGlobalStiffMatrix(3);
    tb.addElementTrusGlobalStiffMatrix(e1, 0, 1);
    tb.addElementTrusGlobalStiffMatrix(e2, 1, 2);
    tb.addElementTrusGlobalStiffMatrix(e3, 0 ,2);
    tb.printGBStiff();







    //BeamTransformationMatrix e1TranSM = calculateBeamTransformationMatrix()

    return 0;
}