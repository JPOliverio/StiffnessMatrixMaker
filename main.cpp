#include <iostream>
#include "RecBeamStiffMatrix.cpp"
#include "TrusGlobalStiffMatrix.cpp"
#include <vector>
using namespace std;

int main(){

    double l1 = 100.0;
    double l2 = 100.0;
    double l3 = 100.0;
    double h = .01;
    double w = .01;
    double y = 2e9;

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

    //made these string vectors. there is then a try catch to see if theres a value or not to reduce the gsm.
    vector<string> displacmentVector = {"d", "0.0", "d", "d", "0.0", "0.0"};
    vector<string> loadVector = {"0.0", "f", "0.0", "-100.0", "f", "f"};

    tb.applyBoundaryConditions(displacmentVector, loadVector);
    tb.printGBStiff();




    return 0;
}