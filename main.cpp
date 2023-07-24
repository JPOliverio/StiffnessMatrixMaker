#include <iostream>
#include "RecBeamStiffMatrix.cpp"
#include <list>
//#include "BeamElement.cpp"
#include "TrusGlobalStiffMatrix.cpp"
using namespace std;

int main(){

    double l1 = 3*1000;
    double l2 = 5*1000;
    double l3 = 4*1000;
    double h = 2.8284;
    double w = 2.8284;
    double y = 1e6;

    RecBeamStiffMatrix e1 = RecBeamStiffMatrix(l3, h, w, y);
    RecBeamStiffMatrix e2 = RecBeamStiffMatrix(l1, h, w, y);
    RecBeamStiffMatrix e3 = RecBeamStiffMatrix(l2, h, w, y);


    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();

    e1.transformSM(90.0);
    e2.transformSM(36.87);
    e3.transformSM(0);


    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();

    TrusGlobalStiffMatrix tb = TrusGlobalStiffMatrix(4);
    tb.addElementTrusGlobalStiffMatrix(e1, 0, 1);
    tb.addElementTrusGlobalStiffMatrix(e2, 2, 1);
    tb.addElementTrusGlobalStiffMatrix(e3, 3 ,1);+

    tb.printGBStiff();


    return 0;
}