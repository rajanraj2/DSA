#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
// 	vector<int> row(n, 0);
// 	vector<int> col(m, 0);
// 	for (int i=0; i<n; i++) {
// 		for (int j=0; j<m; j++) {
// 			if (matrix[i][j] == 0) {
// 				row[i] = 1;
// 				col[j] = 1;
// 			}
// 		}
// 	}
// 	for (int i=0; i<n; i++) {
// 		for (int j=0; j<m; j++) {
// 			if (row[i] || col[j]) {
// 				matrix[i][j] = 0;
// 			}
// 		}
// 	}
// 	return matrix;
// }

// Alternate method 2 : optimal 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// vector<int> row(n, 0);
	// vector<int> col(m, 0);
	int col0 = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				if (j != 0) {
					matrix[0][j] = 0;
				}
				else {
					col0 = 0;
				}
			}
		}
	}
	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (matrix[i][j] != 0) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
	}
	if (matrix[0][0] == 0) {
		for (int j=0; j<m; j++) {
			matrix[0][j] = 0;
		}
	}
	if (col0 == 0) {
		for (int i=0; i<n; i++) {
			matrix[i][0] = 0;
		}
	}
	return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> result = zeroMatrix(matrix, n, m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}