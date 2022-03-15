//
// Created by Damian on 15.03.2022.
//

#include <cmath>
#include <memory>
#include <iostream>
#include "../include/DecodeWord.h"
#include "../include/Matrix.h"

std::vector<int> DecodeWord::repairWord(std::vector<int> wordInByteForm) {
    //8 bytes are control bytes
    auto matrix = std::make_shared<Matrix>(8,wordInByteForm.size()-8);
    auto matrixProduct = matrix->multiplyByVector(wordInByteForm);

    std::vector<int> rows;

    try {
        rows = matrix ->findIdenticalRows(matrixProduct);
    } catch (std::logic_error& e) {
        return wordInByteForm;
    }

    for (int iterator : rows) {
        if(wordInByteForm[iterator] == 0) {
            wordInByteForm[iterator] = 1;
        } else {
            wordInByteForm[iterator] = 0;
        }
    }
    return wordInByteForm;
}


char DecodeWord::decodeWord(std::vector<int> wordinByteForm) {
    //make sure the word is correct
    wordinByteForm = repairWord(wordinByteForm);
    int number = 0;
    int exponent = 0;
    for (int i = 8-1; i >=0 ; i--) {
        //read values from binary to decimal notation
        number += int(pow(2,exponent)) * wordinByteForm.at(i);
        exponent++;
    }
    return char(number);
}

char DecodeWord::decode(std::string wordInByteForm) {
    std::vector<int> temp;
    //String to vector of Int
    //sign(0,1) - '0' create real value in integer type
    for(char sign : wordInByteForm) {
        temp.push_back(sign - '0');
    }
    return decodeWord(temp);
}