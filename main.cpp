#include <iostream>
#include <vector>
#include <fstream>
#include "google.cpp"

using namespace std;

int main() {
    double probability = 0.85;
    Google g1{};

    Matrix initialM = g1.getMatrixFromFile("../connectivity.txt");

    g1.getPageRankMatrix(initialM, probability);


    return 0;
}
