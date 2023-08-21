#include <cmath>
#include <vector>
#include <iostream>
#include "BeamElement.cpp"
using namespace std;

/*This class creates the stiffness matrix of a single element
This is for a beam with a rectangular or square cross section.
12      6L      -12     6L
6L      4L^2    -6L     2L^2
-12     -6L     12      -6L
6L      2L^2    -6L     4L^2
*/


class RecBeamStiffMatrix: public BeamElement
{
    private:
        double length;
        double height;
        double width;
        //vector<vector<double>> stiffnessMatrix; Instead uses inheritance from the BeamTransformation class.
    

    public:

        RecBeamStiffMatrix(double l, double h, double w, double  modulusOfElasticity){

       stiffnessMatrix = vector<vector<double>>(4, vector<double>(4, 0.0));

        length = l;
        height = h;
        width = w;
        double momentOfInertia = (width * pow(height, 3)) / 12.0;

        //if you multiply this by foce you get max deflection
        double EI = modulusOfElasticity * momentOfInertia / pow(length, 3);
        stiffnessMatrix[0][0] = 12.0 * EI;
        stiffnessMatrix[0][1] = 6.0 * length * EI;
        stiffnessMatrix[0][2] = -12.0 * EI;
        stiffnessMatrix[0][3] = 6.0 * length * EI;

        stiffnessMatrix[1][0] = 6.0 * length * EI;
        stiffnessMatrix[1][1] = 4.0 * pow(length, 2) * EI;
        stiffnessMatrix[1][2] = -6.0 * length * EI;
        stiffnessMatrix[1][3] = 2.0 * pow(length, 2) * EI;

        stiffnessMatrix[2][0] = -12.0 * EI;
        stiffnessMatrix[2][1] = -6.0 * length * EI;
        stiffnessMatrix[2][2] = 12.0 * EI;
        stiffnessMatrix[2][3] = -6.0 * length * EI;

        stiffnessMatrix[3][0] = 6.0 * length * EI;
        stiffnessMatrix[3][1] = 2.0 * pow(length, 2) * EI;
        stiffnessMatrix[3][2] = -6.0 * length * EI;
        stiffnessMatrix[3][3] = 4.0 * pow(length, 2) * EI;


    }

    vector<vector<double>> getStiffMatrix(){
        return stiffnessMatrix;
    }

    void printStiffnessMatrix(){
    cout << "Stiffness Matrix:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << stiffnessMatrix[i][j] << " ";
            cout<<endl;
    }
    }
}
    
;
