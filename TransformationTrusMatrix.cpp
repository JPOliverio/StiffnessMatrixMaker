#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/* this class creates the transformation matrix of an elemnt given degree and returns a double vector within a vecotr This is only for trust connected elements.
t = cos^2          cos*sin     -cos^2     -cos*sin 
    cos*sin        sin^2       -cos*sin   -sin^2
    -cos^2         -cos*sin    cos^2      cos*sin
    -cos*sin       -sin^2      cos*sin    sin^2
This assentially rotaes the Stiffness Matrix of an elment to force them to aline.
Tranformation 
//Need to make this a friend of the other class.
*/
class TransformationTrusMatrix{
vector<vector<double>> calculateTransformationMatrix(double angle)
{
    vector<vector<double>> transformationMatrix(4, vector<double>(4, 0.0));

    transformationMatrix[0][0] = pow(cos(angle),2);
    transformationMatrix[0][1] = cos(angle)*sin(angle);
    transformationMatrix[0][2] = -pow(cos(angle),2);
    transformationMatrix[0][3] = -cos(angle)*sin(angle);

    transformationMatrix[1][0] = cos(angle)*sin(angle);
    transformationMatrix[1][1] = pow(sin(angle),2);
    transformationMatrix[1][2] = -cos(angle)*sin(angle);;
    transformationMatrix[1][3] = -pow(sin(angle),2);

    transformationMatrix[2][0] = -pow(cos(angle),2);
    transformationMatrix[2][1] = -cos(angle)*sin(angle);
    transformationMatrix[2][2] = pow(cos(angle),2);
    transformationMatrix[2][3] = cos(angle)*sin(angle);

    transformationMatrix[3][0] = -cos(angle)*sin(angle);
    transformationMatrix[3][1] = -pow(sin(angle),2);
    transformationMatrix[3][2] = cos(angle)*sin(angle);;
    transformationMatrix[3][3] = pow(sin(angle),2);


    return transformationMatrix;
}

};