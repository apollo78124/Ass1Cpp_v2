#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "google.hpp"

using namespace std;

Google::Google() {
    a1 = Matrix();
}

void Google::getPageRankMatrix(Matrix m1, double p) {
    a1 = m1;
    Matrix importance = a1;
    double columnSum = 0;

    for (int j = 0; j < a1.dVec[0].size(); j++)
    {   columnSum = 0;
        for (int i = 0; i < a1.dVec.size(); i++) {
            columnSum += a1.dVec[i][j] ;
        }
        for (int i = 0; i < a1.dVec.size(); i++) {
            importance.dVec[i][j] = a1.dVec[i][j]/columnSum;
            if (columnSum == 0)
                importance.dVec[i][j] = 1/(double)a1.dVec.size();
        }
    }
    cout<<"Importance Matrix\n";
    for (int i = 0; i < importance.dVec.size(); i++)
    {
        for (int j = 0; j < importance.dVec[i].size(); j++) {
            cout<<importance.dVec[i][j] << " ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    /**
     * Transition matrix
     */
    Matrix transition(a1.dVec.size(), a1.dVec[1].size(), 1/(double)a1.dVec[1].size());
    cout<<"Transition Matrix\n";
    for (int i = 0; i < transition.dVec.size(); i++)
    {
        for (int j = 0; j < transition.dVec[i].size(); j++) {
            cout<<transition.dVec[i][j] << " ";
        }
        cout<<'\n';
    }
    for (int i = 0; i < importance.dVec.size(); i++)
    {
        for (int j = 0; j < importance.dVec[0].size(); j++) {
            importance.dVec[i][j] *= p;
        }
    }
    //
    //multiply transition
    //
    //
    for (int i = 0; i < transition.dVec.size(); i++)
    {
        for (int j = 0; j < transition.dVec[0].size(); j++) {
            transition.dVec[i][j] *= (1-p);
        }
    }

    Matrix m = ((transition) + (importance));
    cout<<"\nM\n";
    for (int i = 0; i < m.dVec.size(); i++)
    {
        for (int j = 0; j < m.dVec[i].size(); j++) {
            cout<<m.dVec[i][j] << " ";
        }
        cout<<"\n";
    }

    Matrix rank(a1.dVec.size(), 1, 1);


    Matrix rankTemp((m) * (rank));

    for (int i = 0; i < 200; i++) {
        rankTemp = m * rankTemp;
    }
    cout<<"\n";
    for (int i = 0; i < rankTemp.dVec.size(); i++)
    {
        for (int j = 0; j < rankTemp.dVec[i].size(); j++) {
            cout<<rankTemp.dVec[i][j] << " ";
        }
        cout<<"\n";
    }

    double sumRank;
    for (int i = 0; i < rankTemp.dVec.size(); i++)
    {
        for (int j = 0; j < rankTemp.dVec[i].size(); j++) {
            sumRank += rankTemp.dVec[i][j];
        }
    }

    for (int i = 0; i < rankTemp.dVec.size(); i++)
    {
        for (int j = 0; j < rankTemp.dVec[i].size(); j++) {
            rankTemp.dVec[i][j] /= sumRank;
        }
    }

    cout<<"\nPage Rank"<<endl;
    char pageName = 'A';
    for (int i = 0; i < rankTemp.dVec.size(); i++)
    {
        for (int j = 0; j < rankTemp.dVec[i].size(); j++) {
            cout<<"Page "<<pageName<<": "<< rankTemp.dVec[i][j] << "% ";
            pageName++;
        }
        cout<<"\n";
    }
}

Matrix Google::getMatrixFromFile(string fileName) {
    double *d1 = new double[20000];
    int count = 0;
    ifstream ifile(fileName, ios::in);

    if (!ifile.is_open()) {
        cerr << "There was a problem opening the inputw file!\n";
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

    Matrix m2(d2, count);
    return m2;

}



