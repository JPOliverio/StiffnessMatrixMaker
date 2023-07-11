
#include <vector>

using namespace std;

class TrusGlobalStiffMatrix{

    public:
    TrusGlobalStiffMatrix(int numberOfNodes){
        vector<vector<double>> globalStiffnessMatrix = vector<vector<double>>(numberOfNodes*2,
         vector<double>(numberOfNodes*0, 0.0));

        
    }

};