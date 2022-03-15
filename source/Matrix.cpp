//
// Created by Damian on 15.03.2022.
//

#include <iostream>
#include <sstream>
#include "../include/Matrix.h"


Matrix::Matrix(int dlugoscSlowa, int iloscBitowKontrolnych) {

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
        std::stringstream e;
        e   << "Vector size is inconsistent with the adopted standard in the program";
        throw std::invalid_argument( e.str() );
    }
    std::vector<int> result(colCount);
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < colCount; j++) {
            result.at(i) += this->matrix[i][j] * vector[j];
        }
        result.at(i) %= 2;
    }
    return result;
}

std::vector<int> Matrix::findIdenticalRows(std::vector<int> vectorToCheck) {
    std::vector<int> rows;
    for (int i = 0; i < colCount; i++) {
        if(isColAsVector(i,vectorToCheck)) {
            rows.push_back(i);
            return rows;
        }
    }
    for (int i = 0; i < colCount - 1; i++) {
        for (int j = i+1; j < colCount; j++) {
            if(isColAsVector(i, removeColFromVector(vectorToCheck,j))) {
                rows.push_back(i);
                rows.push_back(j);

                return rows;
            }
        }
    }
    throw std::logic_error("there is no identical line to the vector ");
}

bool Matrix::isColAsVector(int colIndex, std::vector<int> vector) {
    for (int i = 0; i < rowsCount; i++) {
        if(matrix[i][colIndex] != vector.at(i)) {
            return false;
        }
    }
    return true;
}

std::vector<int> Matrix::removeColFromVector(std::vector<int> vector, int index) {
    std::vector<int> difference;
    difference.reserve(vector.size());
    for (int i = 0; i < vector.size(); i++) {
        difference.push_back(abs(vector.at(i) - geValue(i,index)));
    }
    return difference;
}