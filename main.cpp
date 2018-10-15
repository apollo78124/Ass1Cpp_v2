#include <iostream>
#include <vector>
#include <fstream>
#include "matrix.cpp"

using namespace std;

int main() {
    double *d1 = new double[20000];
    fstream input;
    input.open("connectivity.txt");
    int count = 0;
    while (input >> d1[count])
    {
        count++;
    }

    double *d2 = new double[count];

    for (int i = 0; i < count; i++) {
        d2[i] = d1[i];
    }

    Matrix* a1 = new Matrix(d2, count);
    for (int i = 0; i < a1->dVec.size(); i++)
    {
        for (int j = 0; j < a1->dVec[0].size(); j++) {

        }
    }


    input.close ();


// add element to row

    return 0;
}
