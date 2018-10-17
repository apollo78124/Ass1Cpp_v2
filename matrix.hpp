
#ifndef ASS1CPP_V2_MATRIX_HPP
#define ASS1CPP_V2_MATRIX_HPP
#include <vector>
#include <iostream>

using namespace std;

class Matrix {

public:

    //Default Constructor.
    Matrix ();

    //Construct a matrix with n*n size with all attriute values of 0.
    Matrix (int n);

    //Construct a matrix with r rows and c columns.
    Matrix (int r, int c);

    //Construct a matrix with r rows and c columns with default value of v.
    Matrix (int r, int c, double v);

    //Construct a matrix with all the values of array stored in it.
    // Any array with a size which can not be square rooted
    //will return error.
    Matrix (double arr[], int size);

    //Vector to store the values of the matrix.
    vector <vector<double>> dVec;

    //Set the value of the element in the matrix to v which is in
    //row number r and columne number c.
    // PRE : Row and Column index and value to replace the initial value.
    // POST : Parameters not changed.
    // RETURN : void.
    void set_value(int r, int c , double v);

    //Return the value of the element in the
    // PRE : Row and Column index.
    // POST : Parameters not changed.
    // RETURN : value of the element in the position indicated.
    double get_value(int r, int c);

    //Set all the values in the matrix to 0.
    void clear();

    //Destruct the matrix object.
    ~Matrix ();

    //Overload insertion operator.
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

    //Swap the vector of the matrix objects.
    // RETURN : void.
     void matrixSwap(Matrix& m1, Matrix &m2);

};

#endif //ASS1CPP_V2_MATRIX_HPP