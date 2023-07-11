#include <list>
#include <iterator>
#include "BeamElement.cpp"
using namespace std;


class Connectivity: public BeamElement{
    private:
    list<int> firstNode;
    list<int> secoundNode;
    vector<double> displacement;
    vector<double> load;


    public:
    Connectivity(int node1, int node2){
        firstNode.push_back(node1);
        secoundNode.push_back(node2);
    }

    void displacmentVector(int numberOfNodes){
        //the times two is because each node has two degree of freedoms
        displacement = vector<double>(numberOfNodes*2,0); 

    }

    void loadVector(int numberOfNodes){
        //the times two is because each node has two degree of freedoms
        load = vector<double>(numberOfNodes*2,0); 

    }

    //the first value is the displacment in the y direction and the secound the x. negitive is down
    void setDisplacment(int node, double disValue){
        displacement[node] = disValue;
    }

    //the first value is the load in the y direction and the secound the x. negitive is down
    void setLoad(int node, double loadValue){
        load[node] = loadValue;

    }









}
;