#include <iostream>
#include "FrameElement.cpp"
using namespace std;

/*I could have just used the frame transformation matrix but i wanted to dimenstrate inheritance/ function overriding */
class RecFrameStiffMatrix: public FrameElement{
    private:
        double length;
        double height;
        double width;
    public:
        RecFrameStiffMatrix(double l, double h, double w, double  E){
            sm = vector<vector<double>>(6, vector<double>(6, 0.0));
            length = l;
            height = h;
            width = w;

            double momentOfInertia = (width * pow(height, 3)) / 12.0;
            double EI = E * momentOfInertia;
            double a = l*h*w;
            
            sm[0] = {E*a/l, 0, 0 -E*a/l, 0, 0};
            sm[1] = {0, 12*EI/pow(l,3), 6*EI/pow(l,2), 0, -12*EI/pow(l,3), 6*EI/pow(l,2)};
            sm[2] = {0,  6*EI/pow(l,2), 4*EI/l, 0, -6*EI/pow(l,2), 2*EI/l};
            sm[3] = {-E*a/l, 0, 0, E*a/l, 0, 0};
            sm[4] = {0, -12*EI/pow(l,3), -6*EI/pow(l,2), 0, 12*EI/pow(l,3), -6*EI/pow(l,2)};
            sm[5] = {0,  6*EI/pow(l,2), 2*EI/l, 0, -6*EI/pow(l,2), 4*EI/l};
        }

        vector<vector<double>> getStiffMatrix(){
            return sm;
        }

        void printStiffnessMatrix(){
            cout << "Stiffness Matrix:" << endl;
            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 6; ++j)
                    cout << sm[i][j] << " ";
                    cout<<endl;
            }
        }    

};