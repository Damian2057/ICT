//
// Created by Damian on 15.03.2022.
//

#include <cmath>
#include <memory>
#include <iostream>
#include "../include/DecodeWord.h"
#include "../include/Matrix.h"

std::vector<int> DecodeWord::repairWord(std::vector<int> wordInByteForm) {
    //the received word may be incorrect
    //T(original bit) + E(mistakes) = R(received message)
    //length of the coded word 16(8 bits message 8 control bits)

    auto matrix = std::make_shared<Matrix>(8,wordInByteForm.size()-8);
    //we multiply the wordInByteForm by matrix, 0 mean correct, 1 mistake
    auto matrixProduct = matrix->multiplyByVector(wordInByteForm);
    //H R = H E

    std::vector<int> rows;

    try {
        //if rows.size() != that is, we found errors in the transmission
        rows = matrix->searchForErrors(matrixProduct);
    } catch (std::logic_error& e) {
        //0 or more than 2 errors
        return wordInByteForm;
    }

    for (int iterator : rows) {
        //row contains index of property column with mistake
        //repair wordInByteForm(rows.size() == 1 one error, == 2 two errors)
        //repair of found indexes corresponding to the opposite signs, ie as they should be
        if(wordInByteForm[iterator] == 0) {
            wordInByteForm[iterator] = 1;
        } else {
            wordInByteForm[iterator] = 0;
        }
    }
    return wordInByteForm;
}


char DecodeWord::decodeSign(std::vector<int> wordinByteForm) {

    //review if our word is correct, possible error correction on two bits
    wordinByteForm = repairWord(wordinByteForm);

    int number = 0;
    int exponent = 0;
    for (int i = 8-1; i >= 0; i--) {
        //std::cout<<wordinByteForm.at(i);
        //read values from binary to decimal notation
        number += int(pow(2,exponent)) * wordinByteForm.at(i);
        exponent++;
    }
   // std::cout<<number<<std::endl;

    //parse int ASCII to substitute in char

    return char(number);
}

char DecodeWord::decode(std::string wordInByteForm) {
    std::vector<int> temp;
    //String to vector of Int
    //sign(0,1) - '0' create real value in integer type
    for(char sign : wordInByteForm) {
        temp.push_back(sign - '0');
    }

    return decodeSign(temp);
}