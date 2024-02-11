#include<bits/stdc++.h>
using namespace std;
#define N 3

void transpose(int matrix[][N]) {
    int temp;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
        // matrix initialization
        int matrix[3][3]=  { {4,5,6}, {7,8,9}, {10,11,12}};   
        transpose(matrix);
        // printing matrix
    }