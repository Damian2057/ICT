//
// Created by Damian on 15.03.2022.
//

#ifndef TELE_COM_CODEWORD_H
#define TELE_COM_CODEWORD_H

#include <array>
#include <vector>
#include <string>

class CodeWord {

private:
    static std::vector<int> signToBitsVector(char sign);
    static std::vector<int> alignLengthByZeros(std::vector<int> word, int count);
    static std::vector<int> connectBitsAndControlBits(std::vector<int> word, std::vector<int> bits, int count);

    static std::string bitVectorToString(const std::vector<int>& word);
    static std::vector<int> stringToVector(const std::string& text);

public:
    static std::string code(char sign, int countOfControlBites);
};


#endif //TELE_COM_CODEWORD_H
