

#include <vector>
#include <iostream>
#include <C:\Users\348jp\OneDrive\Documents\GitShit\StiffnessMatrixMaker\eigen\Eigen\Dense>

using namespace std;
using namespace Eigen;

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


int main(){

    vector<double> loadvector = {1.0, 2.0, 3.0, 4.0, 5.0, 7.0};

    vector<vector<double>> matvector = vector<vector<double>>(6, vector<double>(6, 0.0));

    const int n = sizeof(loadvector);
    double* ptr = &loadvector[0];

    MatrixXd mat = convert_vvd_to_matrix(matvector);

    Map<VectorXd> vec(ptr,6);

    cout<< vec(0, 0);
    cout << endl;
    cout<< vec(1, 0);
    cout<<endl;
    cout<< vec(2, 0);
    cout<<endl;

    cout<<"mattrix thing"<<endl;
    cout<<mat<<endl;




   // vec << 1, 2, 3, 4, 5, 6;


/*
    for(int i = 0; i < n; i++){
        vec <<loadvector[i];
    }
    */





    return 0;
};
