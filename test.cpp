#include <iostream>
#include <vector>

// Function to calculate the stiffness matrix of a beam element
std::vector<std::vector<double>> calculateStiffnessMatrix(double length, double elasticity, double width, double height)
{
    std::vector<std::vector<double>> stiffnessMatrix(4, std::vector<double>(4, 0.0));

    // Calculate the moment of inertia
    double momentOfInertia = (width * height * height * height) / 12;

    // Calculate the constants
    double EA = elasticity * momentOfInertia / length;
    double EI = elasticity * momentOfInertia / (length * length * length);

    // Populate the stiffness matrix
    stiffnessMatrix[0][0] = 12 * EI / (length * length * length);
    stiffnessMatrix[0][1] = 6 * EI / (length * length);
    stiffnessMatrix[0][2] = -12 * EI / (length * length * length);
    stiffnessMatrix[0][3] = 6 * EI / (length * length);

    stiffnessMatrix[1][0] = 6 * EI / (length * length);
    stiffnessMatrix[1][1] = 4 * EI / length;
    stiffnessMatrix[1][2] = -6 * EI / (length * length);
    stiffnessMatrix[1][3] = 2 * EI / length;

    stiffnessMatrix[2][0] = -12 * EI / (length * length * length);
    stiffnessMatrix[2][1] = -6 * EI / (length * length);
    stiffnessMatrix[2][2] = 12 * EI / (length * length * length);
    stiffnessMatrix[2][3] = -6 * EI / (length * length);

    stiffnessMatrix[3][0] = 6 * EI / (length * length);
    stiffnessMatrix[3][1] = 2 * EI / length;
    stiffnessMatrix[3][2] = -6 * EI / (length * length);
    stiffnessMatrix[3][3] = 4 * EI / length;

    return stiffnessMatrix;
}

int main()
{
    /*
    // Example usage
    double length = 20.0;            // Beam length
    double elasticity = 3e4;         // Elasticity (Young's modulus) of the material
    double width = 0.417;            // Beam width
    double height = 0.417;           // Beam height

    std::vector<std::vector<double>> stiffnessMatrix = calculateStiffnessMatrix(length, elasticity, width, height);

    // Print the stiffness matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << stiffnessMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
    */
   std::cout<<3e4<<std::endl;
}
