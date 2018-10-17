#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include "matrix.hpp"
#include "matrixOp.cpp"

using namespace std;

Matrix::Matrix() {
    vector<double> myRow(1, 0.0);
    dVec.push_back(myRow);
}

Matrix::Matrix(int n) {
    vector<double> myRow(n,0);
    for (int i = 0; i < n; i++)
        dVec.push_back(myRow);
// add element to row
}

Matrix::Matrix (int r, int c) {
    vector<double> myRow(c,0);
    for (int i = 0; i < r; i++)
        dVec.push_back(myRow);
}

Matrix::Matrix (int r, int c, double v) {
    vector<double> myRow(c,v);
    for (int i = 0; i < r; i++)
        dVec.push_back(myRow);
}

Matrix::Matrix (double arr[], int size) {

    if (size < 0)
        throw "Square root of Size is not integer!";
    int root(round(sqrt(size)));
    if (size != root * root)
        throw "Square root of Size is not integer!";

    int n = sqrt (size);

    vector<double> myRow(n,(double) 0.0);
    for (int i = 0; i < n; i++)
        dVec.push_back(myRow);
    int arrayI = 0;
    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++)
        {
            dVec[i][j] = arr[arrayI];
            arrayI++;
        }
        cout << "\n";
    }
}

void Matrix::set_value(int r, int c, double v) {
    if (r < 0 || c < 0 || c >= dVec.size() || r >= dVec[0].size())
        throw "invalid location";
    dVec[c][r] = v;
}

double Matrix::get_value(int r, int c) {
    if (r < 0 || c < 0 || c >= dVec.size() || r >= dVec[0].size())
        throw "invalid location";
    return dVec[c][r];
}

void Matrix::clear() {
    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++)
        {
            dVec[i][j] = 0;
        }
        cout << "\n";
    }
}

void Matrix::matrixSwap(Matrix& m1, Matrix &m2) {
    using std::swap;
    swap(m1.dVec, m2.dVec);
}

Matrix::~Matrix()
{
    //cout<<"Destruct matrix"<<endl;
    }

ostream &operator<<(std::ostream &stream, const Matrix &a1) {
    cout << "Overload insertion operator.\n";
}
