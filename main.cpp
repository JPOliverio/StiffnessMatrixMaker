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

    vector<double> loadVector2 = {0.0, 0.0, 0.0, 0.0, -100.0, 0.0};
    tb.getDisplacment(loadVector2);
    tb.printDisplacment();






    return 0;
}