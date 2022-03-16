//
// Created by Damian on 16.03.2022.
//

#include <memory>
#include <sstream>
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
    std::string temp = file->getText();

    std::stringstream word;
    int index = 0;

    while (index < temp.size()) {
        word << DecodeWord::decode(file->get15symbols(index,temp));
    }

    file->saveFile(word.str(),"../files/decodedOutput.txt");
}