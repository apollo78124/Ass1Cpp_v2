#include "matrix.hpp"

#ifndef ASS1CPP_V2_GOOGLE_HPP
#define ASS1CPP_V2_GOOGLE_HPP



class Google {

public:
    // Store the initial matrix to be processed.
    Matrix a1;

    // Construct a google class.
    Google();

    // Calculatethe Page rank int percentage and
    // from the initial matrix passed in.
    //Print the result and the process on the
    // PRE : Matrix and the probability to pass to other page.
    // POST : m1 and p is unchanged, Only print results to the console.
    // RETURN : void
    void getPageRankMatrix(Matrix m1, double p);

    // Get the Matrix object from the name of a text file.
    // PRE : String of the text file name.
    // POST : Matrix written on the file.
    // RETURN : Matrix
    Matrix getMatrixFromFile(string fileName);
};

#endif //ASS1CPP_V2_GOOGLE_HPP