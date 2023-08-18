#include <cmath>
#include <vector>
using namespace std;

class BeamElement{
    protected:
    vector<vector<double>> stiffnessMatrix;
    vector<vector<double>> TransformedStiffnessMatrix  = vector<vector<double>>(4, vector<double>(4, 0.0));
    vector<vector<double>> TransformationMatrix  = vector<vector<double>>(4, vector<double>(4, 0.0));

  
    public:

    void transformSM(double angle){
    /* this function multiples the stiffness matrix of the element by the below transformation matrix to
    alighn the element's stiffness matrix with the x coordinate plane. Which is required to create a global 
    stiffness matrix.
    t = cos^2          cos*sin     -cos^2     -cos*sin 
    cos*sin        sin^2       -cos*sin   -sin^2
    -cos^2         -cos*sin    cos^2      cos*sin
    -cos*sin       -sin^2      cos*sin    sin^2

    c   s   0   0
    -s  c   0   0  
    0   0   c   s
    0   0   -s  c

    think im multuplying the matric wrong...

    */ 

    angle = angle*3.1415926/180;

    TransformationMatrix[0][0] = cos(angle);
    TransformationMatrix[0][1] = -sin(angle);
    TransformationMatrix[0][2] = 0;
    TransformationMatrix[0][3] = 0;

    TransformationMatrix[1][0] = sin(angle);
    TransformationMatrix[1][1] = cos(angle);
    TransformationMatrix[1][2] = 0;
    TransformationMatrix[1][3] = 0;

    TransformationMatrix[2][0] = 0;
    TransformationMatrix[2][1] = 0;
    TransformationMatrix[2][2] = cos(angle);
    TransformationMatrix[2][3] = -sin(angle);

    TransformationMatrix[3][0] = 0;
    TransformationMatrix[3][1] = 0;
    TransformationMatrix[3][2] = sin(angle);
    TransformationMatrix[3][3] = cos(angle);



    for(int j =0; j < 4; j++){
        for(int i = 0; i < 4; i++){
        TransformedStiffnessMatrix[j][i] = TransformationMatrix[i][0] * stiffnessMatrix[0][j] 
                                            + TransformationMatrix[i][1] * stiffnessMatrix[1][j]
                                            + TransformationMatrix[i][2] * stiffnessMatrix[2][j]
                                            + TransformationMatrix[i][3] * stiffnessMatrix[3][j];
        }
    }


    TransformationMatrix[0][0] = cos(angle);
    TransformationMatrix[0][1] = sin(angle);
    TransformationMatrix[0][2] = 0;
    TransformationMatrix[0][3] = 0;

    TransformationMatrix[1][0] = -sin(angle);
    TransformationMatrix[1][1] = cos(angle);
    TransformationMatrix[1][2] = 0;
    TransformationMatrix[1][3] = 0;

    TransformationMatrix[2][0] = 0;
    TransformationMatrix[2][1] = 0;
    TransformationMatrix[2][2] = cos(angle);
    TransformationMatrix[2][3] = sin(angle);

    TransformationMatrix[3][0] = 0;
    TransformationMatrix[3][1] = 0;
    TransformationMatrix[3][2] = -sin(angle);
    TransformationMatrix[3][3] = cos(angle);

    for(int j =0; j < 4; j++){
        for(int i = 0; i < 4; i++){
        TransformedStiffnessMatrix[j][i] = TransformedStiffnessMatrix[i][0] * TransformationMatrix[0][j] 
                                            + TransformedStiffnessMatrix[i][1] * TransformationMatrix[1][j]
                                            + TransformedStiffnessMatrix[i][2] * TransformationMatrix[2][j]
                                            + TransformedStiffnessMatrix[i][3] * TransformationMatrix[3][j];
        }
    }

    stiffnessMatrix = TransformedStiffnessMatrix;







    /*    TransformedStiffnessMatrix[0][0] = pow(cos(angle),2.0)*stiffnessMatrix[0][0];
    TransformedStiffnessMatrix[0][1] = cos(angle)*sin(angle)*stiffnessMatrix[0][1];
    TransformedStiffnessMatrix[0][2] = -1*(pow(cos(angle),2.0))*stiffnessMatrix[0][2];
    TransformedStiffnessMatrix[0][3] = -1*(cos(angle)*sin(angle))*stiffnessMatrix[0][3];

    TransformedStiffnessMatrix[1][0] = cos(angle)*sin(angle)*stiffnessMatrix[1][0];
    TransformedStiffnessMatrix[1][1] = pow(sin(angle),2.0)*stiffnessMatrix[1][1];
    TransformedStiffnessMatrix[1][2] = -1*(cos(angle)*sin(angle))*stiffnessMatrix[1][2];
    TransformedStiffnessMatrix[1][3] = -1*(pow(sin(angle),2.0))*stiffnessMatrix[1][3];

    TransformedStiffnessMatrix[2][0] = -1*(pow(cos(angle),2.0))*stiffnessMatrix[2][0];
    TransformedStiffnessMatrix[2][1] = -1*(cos(angle)*sin(angle))*stiffnessMatrix[2][1];
    TransformedStiffnessMatrix[2][2] = pow(cos(angle),2.0)*stiffnessMatrix[2][2];
    TransformedStiffnessMatrix[2][3] = cos(angle)*sin(angle)*stiffnessMatrix[2][3];

    TransformedStiffnessMatrix[3][0] = -1*(cos(angle)*sin(angle))*stiffnessMatrix[3][0];
    TransformedStiffnessMatrix[3][1] = -1*(pow(sin(angle),2.0))*stiffnessMatrix[3][1];
    TransformedStiffnessMatrix[3][2] = cos(angle)*sin(angle)*stiffnessMatrix[3][2];
    TransformedStiffnessMatrix[3][3] = pow(sin(angle),2.0)*stiffnessMatrix[3][3];*/


    }
    

    vector<vector<double>> getStiffMatrix(){
        //return stiffnessMatrix;
        return stiffnessMatrix;
    }



};