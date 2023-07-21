#include "BeamElement.cpp"
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



// only works for a single trusds element


    public:
    TrusGlobalStiffMatrix(){}

    TrusGlobalStiffMatrix(list<BeamElement> bElementList){

        int numberOfNodes = (secoundNode.size() > firstNode.size()) ? secoundNode.size():firstNode.size();
        //the times two is because each node has two degree of freedoms
        vector<vector<double>> globalStiffnessMatrix = vector<vector<double>>(numberOfNodes*2,
         vector<double>(numberOfNodes*2, 0.0));

         int fNode = 0;
         int sNode = 0;

         while(bElementList.size()>0){
         stiffnessMatrix = (bElementList.front()).getStiffMatrix();
         fNode = firstNode.front();
         sNode = secoundNode.front();

         bElementList.pop_front();
         firstNode.pop_front();
         secoundNode.pop_front();

         globalStiffnessMatrix[][]

         }


         





         
        
    }

};