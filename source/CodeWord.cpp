//
// Created by Damian on 15.03.2022.
//

#include <algorithm>
#include <memory>
#include <sstream>
#include <iostream>
#include "../include/CodeWord.h"
#include "../include/Matrix.h"


std::string CodeWord::code(char sign, int countOfControlBites) {
    //change word to bite form
    auto wordInByteForm = signToBitsVector(sign);
    //add zeros to complete(fill) the type
    wordInByteForm = alignLengthByZeros(wordInByteForm, countOfControlBites);
    //matrix call
    auto matrix = std::make_shared<Matrix>(8, countOfControlBites);

    //create calculateBits(the computation of the check bits acts as a checksum)
    // H*T,parity check
    auto calculateBits = matrix->multiplyByVector(wordInByteForm);
    //add ControlBits to word(create full form of coded word = bits+calculateBits (8 + 10)
    wordInByteForm = connectBitsAndControlBits(wordInByteForm, calculateBits, countOfControlBites);
    //Parse integer vector to String
    return bitVectorToString(wordInByteForm);
}



//replace the sign with a string of bits in the vector  010110...
std::vector<int> CodeWord::signToBitsVector(char sign) {
    std::vector<int> code;
    //parse char to int value in (ASCII)
    auto num = int(sign);
    //Passage by bits of num
    while (num) {
        if(num & 1) {  // if bit == 1 add 1 in our vector
            code.push_back(1);
        } else { // find 0
            code.push_back(0);
        }
        num >>= 1; //go to the next bit
    }
    while (code.size() < 8) { //fill to 8 bits(code.size must have 8 bits to be considered a valid word)
        code.push_back(0);
    }
    std::reverse(code.begin(), code.end());
    return code;
}


std::vector<int> CodeWord::alignLengthByZeros(std::vector<int> word, int count) {
    //filling 10 consecutive places in vector by 0(some form of initialization)
    while(count > 0) {
        word.push_back(0);
        count--;
    }
    return word;
}

std::vector<int> CodeWord::connectBitsAndControlBits(std::vector<int> word, std::vector<int> bits, int count) {
    //add ControlBits to the word(to sum up)
    for (int i = 0; i < count; i++) {
        word.at(i+8) = bits.at(i);
    }
    return word;
}

std::string CodeWord::bitVectorToString(const std::vector<int> &word) {
    //parse vector to String
    std::stringstream text;
    for(int bit: word) {
        text << bit;
    }
    return text.str();
}

std::vector<int> CodeWord::stringToVector(const std::string &text) {
    //parse String to Vector
    std::vector<int> temp;

    for (char znak : text) {
        temp.push_back(znak - 48);
    }

    return temp;
}