//
// Created by Damian on 15.03.2022.
//

#ifndef TELE_COM_DECODEWORD_H
#define TELE_COM_DECODEWORD_H

#include <vector>
#include <string>

class DecodeWord {

private:
    static std::vector<int> repairWord(std::vector<int> wordInByteForm);
    static char decodeSign(std::vector<int> wordinByteForm);

public:
    static char decode(std::string wordInByteForm);

};


#endif //TELE_COM_DECODEWORD_H
