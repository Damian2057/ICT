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