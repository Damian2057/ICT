//
// Created by Damian on 15.03.2022.
//

#include <algorithm>
#include <memory>
#include <sstream>
#include "../include/CodeWord.h"
#include "../include/Matrix.h"


std::string CodeWord::code(char sign, int countOfControlBites) {
    //change word to bite form
    auto wordInByteForm = signToBitsVector(sign);
    //add zeros to complete the type
    wordInByteForm = addZeros(wordInByteForm,countOfControlBites);

    //matrix call
    auto matrix = std::make_shared<Matrix>(8, countOfControlBites);
    //create controlBits
    auto controlBits = matrix->multiplyByVector(wordInByteForm);
    //add ControlBits to word
    wordInByteForm = createControlBits(wordInByteForm, controlBits, countOfControlBites);

    return vectorToString(wordInByteForm);

}



//replace the sign with a string of bits in the vector  010110...
std::vector<int> CodeWord::signToBitsVector(char sign) {
    std::vector<int> code;
    auto num = int(sign);
    while (num) {
        if(num & 1) {  // find 1
            code.push_back(1);
        } else { // find 0
            code.push_back(0);
        }
        num >>= 1; //Go next
    }
    while (code.size() < 8) { //if  coded word is not proper
        code.push_back(0);
    }
    std::reverse(code.begin(), code.end());
    return code;
}


std::vector<int> CodeWord::addZeros(std::vector<int> word, int count) {
    while(count > 0) {
        word.push_back(0);
        count--;
    }
    return word;
}

std::vector<int> CodeWord::createControlBits(std::vector<int> word, std::vector<int> bits, int count) {
    for (int i = 0; i < count; i++) {
        word.at(i+8) = bits.at(i);
    }
    return word;
}

std::string CodeWord::vectorToString(const std::vector<int> &word) {
    std::stringstream text;
    for(int bit: word) {
        text << bit;
    }
    return text.str();
}

std::vector<int> CodeWord::stringToVector(const std::string &text) {
    std::vector<int> temp;

    for (char znak : text) {
        temp.push_back(znak - 48);
    }

    return temp;
}