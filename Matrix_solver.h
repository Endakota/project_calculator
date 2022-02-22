//
// Created by zhsve on 21.02.2022.
//

#ifndef MAIN_CPP_MATRIX_SOLVER_H
#define MAIN_CPP_MATRIX_SOLVER_H


class Matrix_solver{
public:
    vector<vector<double>>A;
    vector<double>B;
    vector<double>X;
    double d, s;
    int n, i, j, k;

    void set_matrix(vector<vector<double>>A, vector<double>B,vector<double>X, int n){
        this->A=A;
        this->B=B;
        this->X=X;
        this->n=n;
        cout << "Matrix is set";
    }

    vector<double>Gauss(){
        cout << "\n" << "You online";

        for (k = 0; k < n; k++){ // прямой ход
            for (j = k+1; j < n; j++){
                d = A[j][k] / A[k][k]; // формула (1)
                for (i = k; i < n; i++){
                    A[j][i] = A[j][i] - d * A[k][i]; // формула (2)
                    cout << "\n";
                    cout << "A(" << j << ")(" << i << ") = " << A[j][i];
                }
                B[j] = B[j] - d * B[k]; // формула (3)
                cout << "\n";
                cout << "B(" << j << ") = " << B[j];
            }
        }

        for (k = n-1; k >= 0; k--){ // обратный ход
            d = 0;
            //X[k] = (B[k] - d) / A[k][k]; // формула (4)
            for (j = k; j < n; j++){
                s = A[k][j] * X[j]; // формула (4)
                d = d + s; // формула (4)
            }
            X[k] = (B[k] - d) / A[k][k]; // формула (4)
        }
        return X;
    }
};


#endif //MAIN_CPP_MATRIX_SOLVER_H
