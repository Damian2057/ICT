//
// Created by Damian on 16.03.2022.
//

#include <memory>
#include <sstream>
#include <iostream>
#include "../include/FileService.h"
#include "../include/FileFactory.h"
#include "../include/CodeWord.h"
#include "../include/DecodeWord.h"


void FileService::codeFile() {
    auto file = std::make_shared<FileFactory>();
    file->readFileToText("../files/codeInput.txt");
    std::string temp = file->getText();

    std::stringstream code;
    for (char sign : temp) {
        code << CodeWord::code(sign,10)<<"\n";
    }

    file->saveFile(code.str(),"../files/codeOutput.txt");
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
        index +=20;
    }

    file->saveFile(contents.str(),"../files/decodedOutput.txt");
}