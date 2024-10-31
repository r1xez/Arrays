#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftRight(int** array, int rows, int cols, int shifts) {
    shifts = shifts % cols;
    int** temp = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        temp[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            temp[i][(j + shifts) % cols] = array[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}

void shiftLeft(int** array, int rows, int cols, int shifts) {
    shifts = shifts % cols;
    int** temp = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        temp[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            temp[i][(j - shifts + cols) % cols] = array[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

   
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    srand(time(0));

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 10;
        }
    }

    cout << "Initial array:" << endl;
    printArray(array, rows, cols);

    int shifts;
    string direction;
    cout << "Enter the number of shifts: ";
    cin >> shifts;
    cout << "Enter the direction (left, right): ";
    cin >> direction;

    if (direction == "right") {
        shiftRight(array, rows, cols, shifts);
    }
    else if (direction == "left") {
        shiftLeft(array, rows, cols, shifts);
    }

    cout << "Array after shift:" << endl;
    printArray(array, rows, cols);

   
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
