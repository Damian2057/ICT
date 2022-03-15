//
// Created by Damian on 15.03.2022.
//

#ifndef TELE_COM_MATRIX_H
#define TELE_COM_MATRIX_H


#include <vector>

class Matrix {



public:
    Matrix(int dlugoscSlowa, int iloscBitowKontrolnych);
    virtual ~Matrix();
    void toString();
    std::vector<int> multiplyByVector(std::vector<int> wektor);
};


#endif //TELE_COM_MATRIX_H
