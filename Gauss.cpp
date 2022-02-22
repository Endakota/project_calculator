#include <iostream>
#include <vector>
using namespace std;
#include "Matrix_solver.h"

int main(){
    Matrix_solver Ms;

    int n, i, j, k;
    double d, s, aa, bb;

    cout << "n: ";
    cin >> n;

    vector<vector<double>> A(n,vector<double>(n));
    vector<double>B(n);
    vector<double>X(n);

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            A[i][j] = 1;
        }
    }
    for (j = 0; j <= n; j++){
        B[j] = 1;
    }
    for (j = 0; j <= n; j++){
        X[j] = 0;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cout << "\n";
            cout << "A(" << i << ")(" << j << ")=";
            cin >> aa;
            A[i][j] = aa;
        }
    }
    for (j = 0; j < n; j++){
        cout << "\n";
        cout << "B(" << j << ")=";
        cin >> bb;
        B[j] = bb;
    }

    Ms.set_matrix(A,B,X,n);
    vector<double> ans = Ms.Gauss();
    cout << "\n" << "Answer " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3];
    
    return 0;
}