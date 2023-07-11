
#include <vector>
using namespace std;

class BeamElement{
    protected:
    vector<vector<double>> stiffnessMatrix;
    vector<int> connectivity;
    public:

    void transformSM(double angle){
    /* this function multiples the stiffness matrix of the element by the below transformation matrix to
    alighn the element's stiffness matrix with the x coordinate plane. Which is required to create a global 
    stiffness matrix.
    t = cos^2          cos*sin     -cos^2     -cos*sin 
    cos*sin        sin^2       -cos*sin   -sin^2
    -cos^2         -cos*sin    cos^2      cos*sin
    -cos*sin       -sin^2      cos*sin    sin^2
    */
    stiffnessMatrix[0][0] = pow(cos(angle),2)*stiffnessMatrix[0][0];
    stiffnessMatrix[0][1] = cos(angle)*sin(angle)*stiffnessMatrix[0][1];
    stiffnessMatrix[0][2] = -pow(cos(angle),2)*stiffnessMatrix[0][2];
    stiffnessMatrix[0][3] = -cos(angle)*sin(angle)*stiffnessMatrix[0][3];

    stiffnessMatrix[1][0] = cos(angle)*sin(angle)*stiffnessMatrix[1][0];
    stiffnessMatrix[1][1] = pow(sin(angle),2)*stiffnessMatrix[1][1];
    stiffnessMatrix[1][2] = -cos(angle)*sin(angle)*stiffnessMatrix[1][2];
    stiffnessMatrix[1][3] = -pow(sin(angle),2)*stiffnessMatrix[1][3];

    stiffnessMatrix[2][0] = -pow(cos(angle),2)*stiffnessMatrix[2][0];
    stiffnessMatrix[2][1] = -cos(angle)*sin(angle)*stiffnessMatrix[2][1];
    stiffnessMatrix[2][2] = pow(cos(angle),2)*stiffnessMatrix[2][2];
    stiffnessMatrix[2][3] = cos(angle)*sin(angle)*stiffnessMatrix[2][3];

    stiffnessMatrix[3][0] = -cos(angle)*sin(angle)*stiffnessMatrix[3][0];
    stiffnessMatrix[3][1] = -pow(sin(angle),2)*stiffnessMatrix[3][1];
    stiffnessMatrix[3][2] = cos(angle)*sin(angle)*stiffnessMatrix[3][2];
    stiffnessMatrix[3][3] = pow(sin(angle),2)*stiffnessMatrix[3][3];
    }
    
    void setConnectivity(int node1, int node2){
        connectivity = {node1,node2};
    }

    vector<int> getConnectivity(){
        return connectivity;
    }


    vector<vector<double>> getStiffMatrix(){
        return stiffnessMatrix;
    }



};