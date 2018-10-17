#include "matrix.hpp"

#ifndef ASS1CPP_V2_GOOGLE_HPP
#define ASS1CPP_V2_GOOGLE_HPP



class Google {

public:
    Matrix a1;
    Google();
    void getPageRankMatrix(Matrix m1, double p);
    Matrix getMatrixFromFile(string fileName);
};

#endif //ASS1CPP_V2_GOOGLE_HPP