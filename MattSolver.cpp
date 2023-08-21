
#include <vector>
#include <iostream>
#include <C:\Users\348jp\OneDrive\Documents\GitShit\StiffnessMatrixMaker\eigen\Eigen\Dense>



using namespace std;
using namespace Eigen;


class MattSolver{
    private:

    Eigen::VectorXd load;
    Eigen::VectorXd displacmentVector;
    Eigen::MatrixXd globaleStiffMatrix;



    public:
    MattSolver(vector<double> loadVector, vector<vector<double>> gbStiff, int n){

        double* ptr = &loadVector[0];

        Map<VectorXd> load(ptr, n);
        Eigen::VectorXd displacmentVector(n);
        globaleStiffMatrix = convert_vvd_to_matrix(gbStiff);

        displacmentVector = globaleStiffMatrix.colPivHouseholderQr().solve(load);
        cout<<"Displacement Vector"<<endl;
        cout<<displacmentVector<<endl;

    }


    MatrixXd convert_vvd_to_matrix(vector<vector<double> > vvd) {

        std::size_t n_rows = vvd.size();
        std::size_t n_cols = vvd.at(0).size();

        MatrixXd result(n_rows, n_cols);
        result.row(0) = VectorXd::Map(&vvd[0][0], n_cols);

        // Add each vector row to the MatrixXd. 
        for (std::size_t i = 1; i < n_rows; i++) {

            // Make sure that every row of vvd has the same size.
            if (n_cols != vvd.at(i).size()) {
                char buffer[200];
                snprintf(buffer, 200, 
                            "vvd[%ld] size (%ld) does not match vvd[0] size (%ld)",
                            i, vvd.at(i).size(), n_cols);
                string err_mesg(buffer);
                throw std::invalid_argument(err_mesg);
            }

            result.row(i) = VectorXd::Map(&vvd[i][0], n_cols);
        }
        return result;
    }









};