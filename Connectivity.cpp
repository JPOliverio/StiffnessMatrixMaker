#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*This class refers to the relationship between elements and nodes in a system. It specifies which nodes are connected to each element */


class Connectivity{
vector<vector<int>> determineConnectivity(int numElements, int numNodesPerElement)
{
    vector<vector<int>> connectivity(numElements, vector<int>(numNodesPerElement));

    // Assign node indices to each element
    for (int i = 0; i < numElements; ++i) {
        for (int j = 0; j < numNodesPerElement; ++j) {
            connectivity[i][j] = i * numNodesPerElement + j;
        }
    }

    return connectivity;
}

};