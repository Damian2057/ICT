//
// Created by Damian on 15.03.2022.
//

#ifndef TELE_COM_MATRIX_H
#define TELE_COM_MATRIX_H


#include <vector>

class Matrix {

private:
    int rowsCount = 10;
    int ColCount = 10+8;
    int wordLength = 8;
    int matrix[10][10+8] = {
            {1,0,1,1,1,0,1,1, 1,0,0,0,0,0,0,0,0, 0},
            {0,0,0,0,1,1,1,1, 0,1,0,0,0,0,0,0,0, 0},
            {0,0,1,1,0,0,0,0, 0,0,1,0,0,0,0,0,0, 0},

            {1,1,0,1,0,1,1,1, 0,0,0,1,0,0,0,0,0, 0},
            {0,1,0,1,0,0,0,1, 0,0,0,0,1,0,0,0,0, 0},
            {1,0,1,0,1,0,1,1, 0,0,0,0,0,1,0,0,0, 0},

            {1,1,0,1,0,0,1,0, 0,0,0,0,0,0,1,0,0, 0},
            {0,1,0,1,1,0,1,1, 0,0,0,0,0,0,0,1,0, 0},
            {1,1,1,1,1,1,0,1, 0,0,0,0,0,0,0,0,1, 0},

            {1,0,0,1,0,1,1,1, 0,0,0,0,0,0,0,0,0, 1},
    };

    void setValue(int x, int y, int value);

    int geValue(int x, int y);


public:
    Matrix(int dlugoscSlowa, int iloscBitowKontrolnych);
    virtual ~Matrix();

    void toString();
    std::vector<int> multiplyByVector(std::vector<int> vector);
    std::vector<int> findIdenticalRows(std::vector<int> vectorToCheck);
    bool isColAsVector(int colIndex, std::vector<int> vector);
    std::vector<int> removeColFromVector(std::vector<int> vector, int index);
};


#endif //TELE_COM_MATRIX_H
