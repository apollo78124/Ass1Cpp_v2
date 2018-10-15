#include <iostream>
#include <vector>
#include "matrix.hpp"

using namespace std;


bool Matrix::operator==(Matrix m2) {

    if (dVec.size() == m2.dVec.size()
        ||dVec[1].size() == m2.dVec[1].size())
        return false;

    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            if (dVec[i][j] != m2.dVec[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(Matrix m2) {

    if (dVec.size() == m2.dVec.size()
        ||dVec[1].size() == m2.dVec[1].size())
        return true;

    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            if (dVec[i][j] != m2.dVec[i][j])
                return true;
        }
    }

    return false;
}
Matrix& Matrix::operator--() {
    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            dVec[i][j] = dVec[i][j] - 1;
        }
    }
    return *this;
}

Matrix& Matrix::operator++() {
    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            dVec[i][j] = dVec[i][j] + 1;
        }
    }
    return *this;

}



Matrix& Matrix::operator=(Matrix m1) {
    swap(*this, m1);
    return *this;
}

Matrix& Matrix::operator+=(Matrix m2) {
    if (dVec.size() != m2.dVec.size()
        ||dVec[1].size() != m2.dVec[1].size())
        throw "Size is not the same!";

    for (int i = 0; i < m2.dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            dVec[i][j] = dVec[i][j] + m2.dVec[i][j];
        }
    }
    return *this;
}
Matrix& Matrix::operator-=(Matrix m2){
    if (dVec.size() != m2.dVec.size()
        ||dVec[1].size() != m2.dVec[1].size())
        throw "Size is not the same!";


    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            dVec[i][j] = dVec[i][j] - m2.dVec[i][j];
        }
    }
    return *this;
}


Matrix& Matrix::operator+(Matrix m2){
    if (dVec.size() != m2.dVec.size()
        ||dVec[1].size() != m2.dVec[1].size())
        throw "Size is different";
    Matrix *temp = new Matrix(dVec.size(), m2.dVec[1].size());

    for (int i = 0; i < dVec.size(); i++)
    {
        for (int j = 0; j < dVec[i].size(); j++) {
            temp->dVec[i][j] = dVec[i][j] + m2.dVec[i][j];
        }
    }
    return *temp;
}
Matrix& Matrix::operator*(Matrix m2){
    if (dVec.size() < m2.dVec.size()
        ||dVec[1].size() > m2.dVec[1].size())
        throw "Size not multipliable";

    Matrix *temp = new Matrix(dVec.size(), m2.dVec[1].size());
    double loopTemp = 0;

    for (int i = 0; i < temp->dVec.size(); i++)
    {
        for (int j = 0; j < temp->dVec[i].size(); j++) {

            for (int a = 0; a < dVec[i].size(); a++)
            {
                    loopTemp += dVec[i][a] * m2.dVec[a][j];
            }
            temp->dVec[i][j] = loopTemp;
        }
    }

    return *temp;
}
Matrix& Matrix::operator*=(Matrix m2){
    if (dVec.size() < m2.dVec.size()
        ||dVec[1].size() > m2.dVec[1].size())
        throw "Size not multipliable";

    Matrix *temp = new Matrix(dVec.size(), m2.dVec[1].size());
    double loopTemp = 0;

    for (int i = 0; i < temp->dVec.size(); i++)
    {
        for (int j = 0; j < temp->dVec[i].size(); j++) {

            for (int a = 0; a < dVec[i].size(); a++)
            {
                loopTemp += dVec[i][a] * m2.dVec[a][j];
            }
            temp->dVec[i][j] = loopTemp;
        }
    }

    *this = *temp;

    return *this;
}

