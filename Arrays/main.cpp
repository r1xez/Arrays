#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of colums: ";
    cin >> cols;

   
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    int num;
    cout << "Enter the number: ";
    cin >> num;

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0)
                arr[i][j] = num;
            else if (j == 0)
                arr[i][j] = arr[i - 1][cols - 1] + 1; 
            else
                arr[i][j] = arr[i][j - 1] + 1; 
        }
    }

   
    cout << "Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
