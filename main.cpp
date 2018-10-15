#include <iostream>
#include <vector>
#include <fstream>
#include "matrix.cpp"

using namespace std;

int main() {
    double *d1 = new double[20000];
    double p = 0.85;
    int count = 0;
    ifstream ifile("connectivity.txt", ios::in);

    if (!ifile.is_open()) {
        cerr << "There was a problem opening the input file!\n";
        exit(1);
    }

    double num = 0.0;

    while (ifile >> num) {
        d1[count] = num;
        count++;
    }
    ifile.close ();
    double *d2 = new double[count];

    for (int i = 0; i < count; i++) {
        d2[i] = d1[i];
    }

    Matrix* a1 = new Matrix(d2, count);


    Matrix* importance = a1;
    double columnSum = 0;

    for (int j = 0; j < a1->dVec[0].size(); j++)
    {   columnSum = 0;
        for (int i = 0; i < a1->dVec.size(); i++) {
            columnSum += a1->dVec[i][j] ;
        }

        for (int i = 0; i < a1->dVec.size(); i++) {
            importance->dVec[i][j] = importance->dVec[i][j]/columnSum;
            if (columnSum == 0)
                importance->dVec[i][j] = 1/(double)a1->dVec.size();
        }
    }

    /**
     * Transition matrix
     */
    Matrix* transition = new Matrix(a1->dVec.size(), a1->dVec[1].size(), 1/(double)a1->dVec[1].size());

    //multiply importance
    //
    //
    for (int i = 0; i < importance->dVec.size(); i++)
    {
        for (int j = 0; j < importance->dVec[i].size(); j++) {
            importance->dVec[i][j] = importance->dVec[i][j] * p;
        }
    }
    cout<<"Importance Matrix\n";
    for (int i = 0; i < importance->dVec.size(); i++)
    {
        for (int j = 0; j < importance->dVec[i].size(); j++) {
            cout<<importance->dVec[i][j] << " ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    //
    //multiply transition
    //
    //
    for (int i = 0; i < transition->dVec.size(); i++)
    {
        for (int j = 0; j < transition->dVec[i].size(); j++) {
            transition->dVec[i][j] = transition->dVec[i][j] * (1-p);
        }
    }
    cout<<"Transition Matrix\n";
    for (int i = 0; i < transition->dVec.size(); i++)
    {
        for (int j = 0; j < transition->dVec[i].size(); j++) {
            cout<<transition->dVec[i][j] << " ";
        }
        cout<<'\n';
    }
    cout<<"\n";
    Matrix* m = new Matrix((*transition) + (*importance));
    cout<<"M\n";
    for (int i = 0; i < m->dVec.size(); i++)
    {
        for (int j = 0; j < m->dVec[i].size(); j++) {
            cout<<m->dVec[i][j] << " ";
        }
        cout<<"\n";
    }
    cout<<"This does not print for a very weird error! help!";

    Matrix* rank = new Matrix(a1->dVec.size(), 1, (double) 1);


    Matrix* m1 = new Matrix((*m) * (*rank));

    for (int i = 0; i < 30; i++) {
        m1 = new Matrix((*m1) * (*rank));
    }
    cout<<"\n";
    for (int i = 0; i < m1->dVec.size(); i++)
    {
        for (int j = 0; j < m1->dVec[i].size(); j++) {
            cout<<m1->dVec[i][j] << " ";
        }
        cout<<"\n";
    }
    return 0;
}
