//
// Created by Damian on 15.03.2022.
//

#include <iostream>
#include <sstream>
#include "../include/Matrix.h"


Matrix::Matrix(int wordlength, int countOfControlBits) {
}

Matrix::~Matrix() {
}

void Matrix::toString() {
    for (int i=0; i<rowsCount; i++) {
        for (int j=0; j<colCount; j++) {
            std::cout << this->geValue(i, j) << " ";
        }
        std::cout << "\n";
    }
}

int Matrix::geValue(int x, int y) {
    int value;
    try {
        value = this->matrix[x][y];
    } catch (...) {
        std::stringstream e;
        e   << "Wrong index";
        throw std::invalid_argument( e.str() );
    }
    return value;
}

void Matrix::setValue(int x, int y, int value) {
    this->matrix[x][y];
}

std::vector<int> Matrix::multiplyByVector(std::vector<int> vector) {
    if(colCount != vector.size()) {
        //compare size of column and codedWord they must be equal
        std::stringstream e;
        e   << "Vector size is inconsistent with the adopted standard in the program";
        throw std::invalid_argument( e.str() );
    }

    std::vector<int> result(colCount);

    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < colCount; j++) {
            //we multiply our every value in row with every value in vector
            //h11*a1+h12*a2+... = ->
            result.at(i) += this->matrix[i][j] * vector[j];
        }
        //-> result of column %2 causes 1 or 0
        result.at(i) %= 2;
    }
    //if H T has the same 0 message is correct
    return result;
}

std::vector<int> Matrix::searchForErrors(std::vector<int> vectorToCheck) {
    //vector H E

    std::vector<int> rows;
    for (int i = 0; i < colCount; i++) {
        //Finding ONE fault in bits
        if(isColumnAsVector(i, vectorToCheck)) {
            //add index(column index) of bit with error
            rows.push_back(i);
            return rows;
        }
    }

    for (int i = 0; i < colCount - 1; i++) {
        for (int j = i+1; j < colCount; j++) {
            //The H * E result is the sum of the columns with errors
            //which means that we are looking for a pair of which is the sum
            //If the error occurs
            //two times, the product H*E will take the form of the sum of the right columns of the matrix H.
            if(isColumnAsVector(i, substractColFromVector(vectorToCheck, j))) {
                //add two index(column index) of bits with error
                rows.push_back(i);
                rows.push_back(j);

                return rows;
            }
        }
    }

    //The given exception is thrown in two cases
    //the word is faultless
    //there are more than 2 bugs
    throw std::logic_error("there is no identical line to the vector");
}

bool Matrix::isColumnAsVector(int colIndex, std::vector<int> vector) {
    //find vector in matrix
    //H*E compared with H
    for (int i = 0; i < rowsCount; i++) {
        if(matrix[i][colIndex] != vector.at(i)) {
            //error not found
            return false;
        }
    }
    //find error
    return true;
}

std::vector<int> Matrix::substractColFromVector(std::vector<int> vector, int index) {
    //xor the column values with values in index 0,1 -> 1, 1,0 - > 1 0,0;1,1 -> 0
    std::vector<int> difference;
    difference.reserve(vector.size());
    for (int i = 0; i < vector.size(); i++) {
        //xor of the vector
        //we create something like "unfolding"
        difference.push_back(abs(vector.at(i) - geValue(i,index)));
    }

    return difference;
}