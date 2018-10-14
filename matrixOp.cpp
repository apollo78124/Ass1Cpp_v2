#include <iostream>
#include <vector>
#include "matrix.hpp"

using namespace std;


    bool Matrix::operator==(Matrix &m1, Matrix &m2) {

        if (m1.dVec.size() == m2.dVec.size()
        ||m1.dVec[1].size() == m2.dVec[1].size())
            return false;

        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                if (m1.dVec[i][j] != m2.dVec[i][j])
                    return false;
            }
        }

        return true;
    }

    bool Matrix::operator!=(Matrix &m1, Matrix &m2) {

        if (m1.dVec.size() == m2.dVec.size()
            ||m1.dVec[1].size() == m2.dVec[1].size())
            return true;

        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                if (m1.dVec[i][j] != m2.dVec[i][j])
                    return true;
            }
        }

        return false;
    }
    void Matrix::operator--(Matrix &m1) {
        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] = m1.dVec[i][j] + 1;
            }
        }
    }

    void Matrix::operator++(Matrix &m1) {
        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] = m1.dVec[i][j] - 1;
            }
        }

    }

    Matrix& Matrix::operator=(Matrix &m1) {
        swap(*this, m1);
        return *this;
    }

    void Matrix::operator+=(Matrix &m1, Matrix &m2) {
        if (m1.dVec.size() != m2.dVec.size()
            ||m1.dVec[1].size() != m2.dVec[1].size())
            throw "Size is not the same!";

        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] = m1.dVec[i][j] + m2.dVec[i][j];
            }
        }
    }
    void Matrix::operator-=(Matrix &m1, Matrix &m2){
        if (m1.dVec.size() != m2.dVec.size()
            ||m1.dVec[1].size() != m2.dVec[1].size())
            throw "Size is not the same!";


        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] = m1.dVec[i][j] - m2.dVec[i][j];
            }
        }
    }
    void Matrix::operator+(Matrix &m1, Matrix &m2){
        if (m1.dVec.size() != m2.dVec.size()
            ||m1.dVec[1].size() != m2.dVec[1].size())
            return;

        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] + m2.dVec[i][j];
            }
        }
    }
    void Matrix::operator*(Matrix &m1, Matrix &m2){
        if (m1.dVec.size() != m2.dVec.size()
            ||m1.dVec[1].size() != m2.dVec[1].size())
            return;

        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] * m2.dVec[i][j];
            }
        }
    }
    void Matrix::operator*=(Matrix &m1, Matrix &m2){
        if (m1.dVec.size() != m2.dVec.size()
            ||m1.dVec[1].size() != m2.dVec[1].size())
            return;

        for (int i = 0; i < m1.dVec.size(); i++)
        {
            for (int j = 0; j < m1.dVec[i].size(); j++) {
                m1.dVec[i][j] = m1.dVec[i][j] * m2.dVec[i][j];
            }
        }
    }



