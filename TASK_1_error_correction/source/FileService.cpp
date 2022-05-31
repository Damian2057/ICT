//
// Created by Damian on 16.03.2022.
//

#include <memory>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "../include/FileService.h"
#include "../include/FileFactory.h"
#include "../include/CodeWord.h"
#include "../include/DecodeWord.h"


char FileService::controlToChar(std::string sign) {
    //review if our word is correct, possible error correction on two bits
    int number = 0;
    int exponent = 0;
    for (int i = 8; i < 16; i++) {
        //read values from binary to decimal notation
        number += int(pow(2,exponent)) * sign.at(i);
        exponent++;
    }
    //parse int ASCII to substitute in char

    return char(number);
}


void FileService::codeFile() {
    auto file = std::make_shared<FileFactory>();
    file->readFileToText("../files/codeInput.txt");
    std::string temp = file->getText();

    std::stringstream code;
    std::stringstream tofileCode;
    for (char sign : temp) {

        std::string codedsign = CodeWord::code(sign,8);
        tofileCode << sign << controlToChar(codedsign);
    }

    file->saveFile(tofileCode.str(),"../files/codeOutput");
}


std::string FileService::convertToArray(std::string twoSigns) {
    std::vector<int> code;
    for (auto s:twoSigns) {
        std::vector<int> codedONEsign;
        //parse char to int value in (ASCII)
        auto num = abs(int(s));
        //Passage by bits of num
        while (num) {
            if(num & 1) {  // if bit == 1 add 1 in our vector
                codedONEsign.push_back(1);
            } else { // find 0
                codedONEsign.push_back(0);
            }
            num >>= 1; //go to the next bit
        }
        while (codedONEsign.size() < 8) {
            codedONEsign.insert(codedONEsign.end(),0);
            //code.push_back(0);
        }
        std::reverse(codedONEsign.begin(), codedONEsign.end());
        for (int i = 0; i < codedONEsign.size(); ++i) {
            code.push_back(codedONEsign.at(i));
        }
    }
    return bitsToString(code);
}


std::string FileService::bitsToString(const std::vector<int> &word) {
    //parse vector to String
    std::stringstream text;
    for(int bit: word) {
        text << bit;
    }
    return text.str();
}



void FileService::deCodeFile() {
    auto file = std::make_shared<FileFactory>();
    file->readFileToText("../files/codeOutput");
    //temp has all code "arrays"

    std::stringstream contents;

    std::string codedArray = file->getText();
    for (int i = 0; i <codedArray.size(); i += 2) {
        std::string chain;
        chain.push_back(codedArray.at(i));
        chain.push_back(codedArray.at(i+1));
        contents << DecodeWord::decode(convertToArray(chain));
    }

    file->saveFile(contents.str(),"../files/decodedOutput.txt");
}