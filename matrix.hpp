
#ifndef ASS1CPP_V2_MATRIX_HPP
#define ASS1CPP_V2_MATRIX_HPP
#include <vector>
#include <iostream>

using namespace std;

class Matrix {

public:
    Matrix ();
    Matrix (int n);
    Matrix (int r, int c);
    Matrix (int r, int c, double v);
    Matrix (double arr[], int size);

    vector <vector<double>> dVec;
    void set_value(int r, int c , double v);
    double get_value(int r, int c);
    void clear();
    ~Matrix ();
    friend ostream &operator<<(std::ostream &stream, const Matrix &a1);
     bool operator==(const Matrix m2);
     bool operator!=(Matrix m2);
     Matrix& operator--();
     Matrix& operator++();
     Matrix& operator=(Matrix m1);
     Matrix& operator+=(Matrix m2);
     Matrix& operator-=(Matrix m2);
     friend Matrix operator+(Matrix m1, Matrix m2);
     friend Matrix operator*(Matrix m1, Matrix m2);
     Matrix& operator*=(Matrix m2);

     void matrixSwap(Matrix& m1, Matrix &m2);


};

#endif //ASS1CPP_V2_MATRIX_HPP