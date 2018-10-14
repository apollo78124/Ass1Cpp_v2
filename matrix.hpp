//
// Created by dldms on 10/14/2018.
//

#ifndef ASS1CPP_V2_MATRIX_HPP
#define ASS1CPP_V2_MATRIX_HPP

#endif //ASS1CPP_V2_MATRIX_HPP

using namespace std;

class Matrix {

public:
    vector <vector<double>> dVec;
    Matrix ();
    Matrix (int n);
    Matrix (int r, int c);
    Matrix (double a[]);
    void set_value(int r, int c , double v);
    double get_value(int r, int c);
    void clear();
    ~Matrix ();
    friend ostream &operator<<(std::ostream &stream, const Matrix &a1);
     bool operator==(const Matrix &m2);
     bool operator!=(Matrix &m2);
     Matrix& operator--();
     Matrix& operator++();
     Matrix& operator=(Matrix m1);
     Matrix& operator+=(Matrix &m2);
     Matrix& operator-=(Matrix &m2);
     Matrix& operator+(Matrix &m2);
     Matrix& operator*(Matrix &m2);
     Matrix& operator*=(Matrix &m2);


};
