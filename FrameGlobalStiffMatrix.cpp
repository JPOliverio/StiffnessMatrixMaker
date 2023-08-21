#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "math.h"
#include "MattSolver.cpp"
#include <C:\Users\348jp\OneDrive\Documents\GitShit\StiffnessMatrixMaker\eigen\Eigen\Dense>

//#include "FrameElement.cpp"


using namespace std;
using Eigen::MatrixXd;

class FrameGlobalStiffMatrix{

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
    int n = 0;




// only works for a single trusds element


    public:
    FrameGlobalStiffMatrix(int numberOfNodes){
        numNodes = numberOfNodes;
        globalStiffnessMatrix = vector<vector<double>>(numberOfNodes*3, vector<double>(numberOfNodes*3, 0.0));
    }

    void addElementTrusGlobalStiffMatrix(FrameElement element, int firstNode, int secoundNode){
         stiffnessMatrix = element.getStiffMatrix();


        // the times 3 is because there are 3 degree of freedoms for each node.
         int d1x = firstNode*3;
         int d1y = d1x+1; //1
         int d1m = d1y+1;
         int d2x = secoundNode*3;
         int d2y = d2x+1; //2
         int d2m = d2y+1;

         /*not tested yet. should work. hopfully. 
         This is what is used to build the global stiffness matrix from the local frame elemens Stiffness matricis
         */
         globalStiffnessMatrix[d1x][d1x] = stiffnessMatrix[0][0] + globalStiffnessMatrix[d1x][d1x];
         globalStiffnessMatrix[d1x][d1y] = stiffnessMatrix[0][1] + globalStiffnessMatrix[d1x][d1y];
         globalStiffnessMatrix[d1x][d1m] = stiffnessMatrix[0][2] + globalStiffnessMatrix[d1x][d1m];
         globalStiffnessMatrix[d1x][d2x] = stiffnessMatrix[0][3] + globalStiffnessMatrix[d1x][d2x];
         globalStiffnessMatrix[d1x][d2y] = stiffnessMatrix[0][4] + globalStiffnessMatrix[d1x][d2y];
         globalStiffnessMatrix[d1x][d2m] = stiffnessMatrix[0][5] + globalStiffnessMatrix[d1x][d2m];
         
         globalStiffnessMatrix[d1y][d1x] = stiffnessMatrix[1][0] + globalStiffnessMatrix[d1y][d1x];
         globalStiffnessMatrix[d1y][d1y] = stiffnessMatrix[1][1] + globalStiffnessMatrix[d1y][d1y];
         globalStiffnessMatrix[d1y][d1m] = stiffnessMatrix[1][2] + globalStiffnessMatrix[d1y][d1m];
         globalStiffnessMatrix[d1y][d2x] = stiffnessMatrix[1][3] + globalStiffnessMatrix[d1y][d2x];
         globalStiffnessMatrix[d1y][d2y] = stiffnessMatrix[1][4] + globalStiffnessMatrix[d1y][d2y];
         globalStiffnessMatrix[d1y][d2m] = stiffnessMatrix[1][5] + globalStiffnessMatrix[d1y][d2m];

         globalStiffnessMatrix[d1m][d1x] = stiffnessMatrix[2][0] + globalStiffnessMatrix[d1m][d1x];
         globalStiffnessMatrix[d1m][d1y] = stiffnessMatrix[2][1] + globalStiffnessMatrix[d1m][d1y];
         globalStiffnessMatrix[d1m][d1m] = stiffnessMatrix[2][2] + globalStiffnessMatrix[d1m][d1m];
         globalStiffnessMatrix[d1m][d2x] = stiffnessMatrix[2][3] + globalStiffnessMatrix[d1m][d2x];
         globalStiffnessMatrix[d1m][d2y] = stiffnessMatrix[2][4] + globalStiffnessMatrix[d1m][d2y];
         globalStiffnessMatrix[d1m][d2m] = stiffnessMatrix[2][5] + globalStiffnessMatrix[d1m][d2m];

         globalStiffnessMatrix[d2x][d1x] = stiffnessMatrix[3][0] + globalStiffnessMatrix[d2x][d1x];
         globalStiffnessMatrix[d2x][d1y] = stiffnessMatrix[3][1] + globalStiffnessMatrix[d2x][d1y];
         globalStiffnessMatrix[d2x][d1m] = stiffnessMatrix[3][2] + globalStiffnessMatrix[d2x][d1m];
         globalStiffnessMatrix[d2x][d2x] = stiffnessMatrix[3][3] + globalStiffnessMatrix[d2x][d2x];
         globalStiffnessMatrix[d2x][d2y] = stiffnessMatrix[3][4] + globalStiffnessMatrix[d2x][d2y];
         globalStiffnessMatrix[d2x][d2m] = stiffnessMatrix[3][5] + globalStiffnessMatrix[d2x][d2m];

         globalStiffnessMatrix[d2y][d1x] = stiffnessMatrix[4][0] + globalStiffnessMatrix[d2y][d1x];
         globalStiffnessMatrix[d2y][d1y] = stiffnessMatrix[4][1] + globalStiffnessMatrix[d2y][d1y];
         globalStiffnessMatrix[d2y][d1m] = stiffnessMatrix[4][2] + globalStiffnessMatrix[d2y][d1m];
         globalStiffnessMatrix[d2y][d2x] = stiffnessMatrix[4][3] + globalStiffnessMatrix[d2y][d2x];
         globalStiffnessMatrix[d2y][d2y] = stiffnessMatrix[4][4] + globalStiffnessMatrix[d2y][d2y];
         globalStiffnessMatrix[d2y][d2m] = stiffnessMatrix[4][5] + globalStiffnessMatrix[d2y][d2m];

         globalStiffnessMatrix[d2m][d1x] = stiffnessMatrix[5][0] + globalStiffnessMatrix[d2m][d1x];
         globalStiffnessMatrix[d2m][d1y] = stiffnessMatrix[5][1] + globalStiffnessMatrix[d2m][d1y];
         globalStiffnessMatrix[d2m][d1m] = stiffnessMatrix[5][2] + globalStiffnessMatrix[d2m][d1m];
         globalStiffnessMatrix[d2m][d2x] = stiffnessMatrix[5][3] + globalStiffnessMatrix[d2m][d2x];
         globalStiffnessMatrix[d2m][d2y] = stiffnessMatrix[5][4] + globalStiffnessMatrix[d2m][d2y];
         globalStiffnessMatrix[d2m][d2m] = stiffnessMatrix[5][5] + globalStiffnessMatrix[d2m][d2m];
    }

    void applyBoundaryConditions(vector<string> displacmentVector, vector<string> loadVector){
        // you need to apply the bounray condtions and reduce the matrix to detrmine the detrminte 

        //deletes the column. Credit goes to https://stackoverflow.com/questions/27264953/how-to-delete-column-in-2d-vector-c
        //deltes from right to left
        bool result = false;
        int dStart = displacmentVector.size() -1;
        for(dStart; dStart >= 0 ; --dStart){
            try{
                stod(displacmentVector[dStart])==0;
                result = true;
            }catch(...){
                result = false;
            }
            if(result){
                for_each(globalStiffnessMatrix.begin(), globalStiffnessMatrix.end(), [&](vector<double>& row) {
                row.erase(next(row.begin(), dStart));
                });
            }
        }
        

        
        //deletes rows from bottom to top.
        int lStart = loadVector.size() -1;
        for(lStart; lStart >= 0 ; --lStart){
            try{
                stod(loadVector[lStart]); // trys to convert the string to a double
                result = false;
            }catch(...){
                result = true;
            }
            if(result){
                globalStiffnessMatrix.erase(globalStiffnessMatrix.begin() + lStart);
            }
        }




        n = globalStiffnessMatrix[0].size();

        // from here I could use Gaussian elimination. to make it simpler but i think i'll just solve the equation.
        
    }     

    


    void printGBStiff(){
        cout<< "Global Stiffness Matrix:" << endl;
        int sizeStiff = numNodes*3;
        for (int i = 0; i < globalStiffnessMatrix.size(); ++i)
        {
            for (int j = 0; j < globalStiffnessMatrix[0].size(); ++j){
                cout << globalStiffnessMatrix[i][j] << " | ";
            }
            cout<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------";
            cout<<endl;
        }
    }

    void getDisplacment(vector<double> loadVector){
        MattSolver pink = MattSolver(loadVector, globalStiffnessMatrix, n);
        vector<double> mouse = pink.getD();

    }

    void printDisplacment(){
        cout<<"Displacment Vector"<<endl;
        cout<<fixed;
        cout.precision(5);
        for(int i = 0; i < n; i++){
            cout<<displacement[i]<< " | ";
        }
        cout<<endl;
    }


};