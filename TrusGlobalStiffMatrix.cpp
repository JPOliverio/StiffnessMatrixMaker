#include <iostream>
//#include "RecBeamStiffMatric.cpp"
#include <vector>
#include <list>


using namespace std;

class TrusGlobalStiffMatrix{

    protected:
    list<int> firstNode;
    list<int> secoundNode;
    list<int> elementList;
    vector<double> displacement;
    vector<double> load;
    int elementCount = 1;
    vector<vector<double>> stiffnessMatrix;
    vector<vector<double>> globalStiffnessMatrix;
    int numNodes;




// only works for a single trusds element


    public:
    TrusGlobalStiffMatrix(int numberOfNodes){
        numNodes = numberOfNodes;
        globalStiffnessMatrix = vector<vector<double>>(numberOfNodes*2, vector<double>(numberOfNodes*2, 0.0));
    }

    void addElementTrusGlobalStiffMatrix(BeamElement element, int firstNode, int secoundNode){
         stiffnessMatrix = element.getStiffMatrix();
        //this isnt making the fullstiffness matrix...... my logic is way off...
         int d1x = firstNode*2;
         int d1y = d1x+1; //1
         int d2x = secoundNode*2;
         int d2y = d2x+1; //2
         
         globalStiffnessMatrix[d1x][d1x] = stiffnessMatrix[0][0] + globalStiffnessMatrix[d1x][d1x];
         globalStiffnessMatrix[d1x][d1y] = stiffnessMatrix[0][1] + globalStiffnessMatrix[d1x][d1y];
         globalStiffnessMatrix[d1x][d2x] = stiffnessMatrix[0][2] + globalStiffnessMatrix[d1x][d2x];
         globalStiffnessMatrix[d1x][d2y] = stiffnessMatrix[0][3] + globalStiffnessMatrix[d1x][d2y];

         globalStiffnessMatrix[d1y][d1x] = stiffnessMatrix[1][0] + globalStiffnessMatrix[d1y][d1x];
         globalStiffnessMatrix[d1y][d1y] = stiffnessMatrix[1][1] + globalStiffnessMatrix[d1y][d1y];
         globalStiffnessMatrix[d1y][d2x] = stiffnessMatrix[1][2] + globalStiffnessMatrix[d1y][d2x];
         globalStiffnessMatrix[d1y][d2y] = stiffnessMatrix[1][3] + globalStiffnessMatrix[d1y][d2y];

         globalStiffnessMatrix[d2x][d1x] = stiffnessMatrix[2][0] + globalStiffnessMatrix[d2x][d1x];
         globalStiffnessMatrix[d2x][d1y] = stiffnessMatrix[2][1] + globalStiffnessMatrix[d2x][d1y];
         globalStiffnessMatrix[d2x][d2x] = stiffnessMatrix[2][2] + globalStiffnessMatrix[d2x][d2x];
         globalStiffnessMatrix[d2x][d2y] = stiffnessMatrix[2][3] + globalStiffnessMatrix[d2x][d2y];

         globalStiffnessMatrix[d2y][d1x] = stiffnessMatrix[3][0] + globalStiffnessMatrix[d2y][d1x];
         globalStiffnessMatrix[d2y][d1y] = stiffnessMatrix[3][1] + globalStiffnessMatrix[d2y][d1y];
         globalStiffnessMatrix[d2y][d2x] = stiffnessMatrix[3][2] + globalStiffnessMatrix[d2y][d2x];
         globalStiffnessMatrix[d2y][d2y] = stiffnessMatrix[3][3] + globalStiffnessMatrix[d2y][d2y];         
         }


        void printGBStiff(){
         cout<< "Global Stiffness Matrix:" << endl;
         int sizeStiff = numNodes*2;
         for (int i = 0; i < sizeStiff; ++i)
         {
            for (int j = 0; j < sizeStiff; ++j)
                cout << globalStiffnessMatrix[i][j] << " ";
                cout<<endl;
         }
        }


};