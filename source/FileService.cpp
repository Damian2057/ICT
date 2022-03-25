//
// Created by Damian on 16.03.2022.
//

#include <memory>
#include <sstream>
#include <iostream>
#include <cmath>
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

    std::cout<<tofileCode.str();

    file->saveFile(tofileCode.str(),"../files/codeOutput");
}

void FileService::deCodeFile() {
    auto file = std::make_shared<FileFactory>();
    file->readFileToText("../files/decodedInput.txt");
    //temp has all code "arrays"

    std::string codedArray = file->getText();

    std::stringstream contents;
    int index = 0;
    //read file line by line
    while (index < codedArray.size()) {
        contents << DecodeWord::decode(file->getLineFromFile(index, codedArray));

        //index +20 because enter in codedArray after 18 sign
        index +=18;
    }

    file->saveFile(contents.str(),"../files/decodedOutput.txt");
}