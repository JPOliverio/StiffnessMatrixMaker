#include <iostream>
#include "StiffMatrix.cpp"
using namespace std;

int main(){

        double** stiffnessMatrix = new double*[4];
    for (int i = 0; i < 4; ++i){
        stiffnessMatrix[i] = new double[4];
    }

        double l=10;
        double h=.2;
        double w=.1;
        double y=200e9;
        StiffMatrix sm = StiffMatrix(l, h, w, y, stiffnessMatrix);

            std::cout << "Stiffness Matrix:" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            std::cout << stiffnessMatrix[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}