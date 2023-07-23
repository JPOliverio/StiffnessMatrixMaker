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
        double h=4/12;
        double w=4/12;
        double y=3e9;

    list<BeamElement> trusElements;

    RecBeamStiffMatrix e1 = RecBeamStiffMatrix(20, h, w, y);
    RecBeamStiffMatrix e2 = RecBeamStiffMatrix(16, h, w, y);
    RecBeamStiffMatrix e3 = RecBeamStiffMatrix(12, h, w, y);
    RecBeamStiffMatrix e4 = RecBeamStiffMatrix(16, h, w, y);
    RecBeamStiffMatrix e5 = RecBeamStiffMatrix(20, h, w, y);
    RecBeamStiffMatrix e6 = RecBeamStiffMatrix(20, h, w, y);
    RecBeamStiffMatrix e7 = RecBeamStiffMatrix(16, h, w, y);
    RecBeamStiffMatrix e8 = RecBeamStiffMatrix(12, h, w, y);

    double deg1 = 0.6435011088*180/3.141592678;
    double deg2 = 180 -deg1;
    double deg3 = 90;

    cout<<"e1"<<endl;
    e1.printStiffnessMatrix();
    cout<<"e2"<<endl;
    e2.printStiffnessMatrix();
    cout<<"e3"<<endl;
    e3.printStiffnessMatrix();

    e1.transformSM(deg1);
    e2.transformSM(0);
    e3.transformSM(deg3);
    e4.transformSM(0);
    e5.transformSM(deg2);
    e6.transformSM(deg1);
    e7.transformSM(0);
    e8.transformSM(deg3);

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
    trusElements.push_back(e4);
    trusElements.push_back(e5);
    trusElements.push_back(e6);
    trusElements.push_back(e7);
    trusElements.push_back(e8);


    TrusGlobalStiffMatrix tb = TrusGlobalStiffMatrix(8);
    tb.addElementTrusGlobalStiffMatrix(e1, 0, 2);
    tb.addElementTrusGlobalStiffMatrix(e2, 0, 1);
    tb.addElementTrusGlobalStiffMatrix(e3, 1 ,2);
    tb.addElementTrusGlobalStiffMatrix(e4, 2, 4);
    tb.addElementTrusGlobalStiffMatrix(e5, 2, 3);
    tb.addElementTrusGlobalStiffMatrix(e6, 1 ,4);
    tb.addElementTrusGlobalStiffMatrix(e7, 1, 3);
    tb.addElementTrusGlobalStiffMatrix(e8, 3 ,4);
    tb.printGBStiff();







    //BeamTransformationMatrix e1TranSM = calculateBeamTransformationMatrix()

    return 0;
}