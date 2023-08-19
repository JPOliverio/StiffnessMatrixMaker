#include <iostream>
#include "RecBeamStiffMatrix.cpp"
#include "RecFrameStiffMatrix.cpp"
#include "TrusGlobalStiffMatrix.cpp"
#include <vector>
#include "FrameGlobalStiffMatrix.cpp"

using namespace std;

/*
Truss elment carry only axial forces.
Beam elments carry shear forces and bending moment.
Frame element carry shear, bending and axial forces.

the problem with my code is it only loks at beam or truss. I need to look at frame.

*/

int main(){

    double l1 = 2;
    double l2 = 2;
    double h = 0.12;
    double w = 0.12;
    double y = 2e1;






    RecFrameStiffMatrix e1 = RecFrameStiffMatrix(l1, h, w, y);
    RecFrameStiffMatrix e2 = RecFrameStiffMatrix(l2, h, w, y);

    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;                                        
    e2.printStiffnessMatrix();

    e1.transformSM(90.0);
    e2.transformSM(0.0);

    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();

    FrameGlobalStiffMatrix tb = FrameGlobalStiffMatrix(3);
    tb.addElementTrusGlobalStiffMatrix(e1, 0, 1);
    tb.addElementTrusGlobalStiffMatrix(e2, 1, 2);
    tb.printGBStiff();


    vector<string> displacmentVector = {"0.0", "0.0", "0.0", "d", "d", "m", "d", "d", "m"};
    vector<string> loadVector = {"f", "f", "m", "0.0", "0.0", "0.0", "0.0", "-100.0", "0.0"};

    tb.applyBoundaryConditions(displacmentVector, loadVector);
    tb.printGBStiff();



    /* This was for the truss or beam method that is not working
    double l1 = 1.0;
    double l2 = 1.0;
    double l3 = 1.0;
    double h = .1;
    double w = .1;
    double y = 2e11;

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
    e2.transformSM(300.0);
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

    */




    return 0;
}