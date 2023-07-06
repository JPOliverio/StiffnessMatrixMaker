#include <cmath>
using namespace std;


class StiffMatrix
{
    private:
        double length;
        double height;
        double width;
        double modulusOfElasticity;
    

    public:
        StiffMatrix(double l, double h, double w, double y, double** stiffnessMatrix){
        length = l;
        height = h;
        width = w;
        modulusOfElasticity = y;
        double momentOfInertia = (width * pow(height, 3)) / 12.0;
        double factor = modulusOfElasticity * momentOfInertia / pow(length, 3);
        stiffnessMatrix[0][0] = 12.0 * factor;
        stiffnessMatrix[0][1] = 6.0 * length * factor;
        stiffnessMatrix[0][2] = -12.0 * factor;
        stiffnessMatrix[0][3] = 6.0 * length * factor;

        stiffnessMatrix[1][0] = 6.0 * length * factor;
        stiffnessMatrix[1][1] = 4.0 * pow(length, 2) * factor;
        stiffnessMatrix[1][2] = -6.0 * length * factor;
        stiffnessMatrix[1][3] = 2.0 * pow(length, 2) * factor;

        stiffnessMatrix[2][0] = -12.0 * factor;
        stiffnessMatrix[2][1] = -6.0 * length * factor;
        stiffnessMatrix[2][2] = 12.0 * factor;
        stiffnessMatrix[2][3] = -6.0 * length * factor;

        stiffnessMatrix[3][0] = 6.0 * length * factor;
        stiffnessMatrix[3][1] = 2.0 * pow(length, 2) * factor;
        stiffnessMatrix[3][2] = -6.0 * length * factor;
        stiffnessMatrix[3][3] = 4.0 * pow(length, 2) * factor;
    }
}
    
;
