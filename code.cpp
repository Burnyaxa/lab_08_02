#include <iostream>
#include <ctime>

using namespace std;

int **getMatrix(int n);
void initializeMatrix(int **matrix, int n);
void outputMatrix(int **matrix, int n);
int maxElementBelowDiagonals(int **matrix, int n, int i, int j);
void changeElement(int **first_matrix, int **second_matrix, int n);

int main(){
	srand(time(NULL));
	int n; 
	cout << "Insert a size of the matrix : "; cin >> n;
	int **A = getMatrix(n); 
	int **B = getMatrix(n);
	initializeMatrix(A, n);
	cout << "Your matrix A : " << endl;
	outputMatrix(A, n);
	changeElement(A,B, n);
	cout << "Your matrix B : " << endl;
	outputMatrix(B, n);
	system("pause");
	return 0;
}

int **getMatrix( int n){
	int **matrix = new int *[n];
	for (int i = 0; i < n; i++){
		matrix[i] = new int[n];
	}
	return matrix;
}

void initializeMatrix(int **matrix, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			matrix[i][j] = rand() % 30;
		}
	}
}

void outputMatrix(int **matrix, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int maxElementBelowDiagonals(int **matrix, int n, int i, int j){
	int max = 0;
	int ch = 0;
	for (int x = i; x < n; x++,ch++){
		for (int y = 0; y < n; y++){
			if ((y >= j-ch) && (y <= j+ch)){
				if (matrix[x][y] > max){
					max = matrix[x][y];
				}
			}
		}
	}
	return max;
}

void changeElement(int **first_matrix, int **second_matrix, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			second_matrix[i][j] = maxElementBelowDiagonals(first_matrix, n, i, j);
		}
	}
}