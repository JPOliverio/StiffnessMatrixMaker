#include <iostream>
#include "RecBeamStiffMatrix.cpp"
#include <list>
//#include "BeamElement.cpp"
#include "TrusGlobalStiffMatrix.cpp"
using namespace std;

int main(){

    double l1 = 1.0;
    double l2 = 1.0;
    double l3 = 1.0;
    double h = 0.01;
    double w = 0.01;
    double y = 2e8;

    RecBeamStiffMatrix e1 = RecBeamStiffMatrix(l3, h, w, y);
    RecBeamStiffMatrix e2 = RecBeamStiffMatrix(l1, h, w, y);
    RecBeamStiffMatrix e3 = RecBeamStiffMatrix(l2, h, w, y);


    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();

    e1.transformSM(60.0);
    e2.transformSM(300);
    e3.transformSM(0);


    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();

    TrusGlobalStiffMatrix tb = TrusGlobalStiffMatrix(3);
    tb.addElementTrusGlobalStiffMatrix(e1, 0, 1);
    tb.addElementTrusGlobalStiffMatrix(e2, 1, 2);
    tb.addElementTrusGlobalStiffMatrix(e3, 0 ,2);
    tb.printGBStiff();

    vector<double> displacmentVector = {0.0, 0.0, 1.0, 1.0, 0.0, 0.0};
    vector<double> loadVector = {0.0, 0.0, 0.0, -100, 0.0, 0.0};

    tb.applyBoundaryConditions(displacmentVector, loadVector);
    tb.printGBStiff();




    return 0;
}