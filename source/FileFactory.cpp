//
// Created by Damian on 15.03.2022.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "../include/FileFactory.h"


std::string FileFactory::getText() {
    return text;
}

std::string FileFactory::get15symbols(int &index, std::string &text) {
    std::stringstream symbol;
    //
    for (int i = 0; i < 18; ++i) {
        symbol << text[i+index];
    }
    index +=20;
    return symbol.str();

}

void FileFactory::saveFile(const std::string &textToSave, const std::string &output) {
    std::ofstream file(output, std::ios::binary);
    file << std::noskipws;
    file << textToSave;
    file.close();
}

void FileFactory::readFileToText(const std::string &input) {
    std::ifstream file(input, std::ios::binary);
    std::getline(file, text, '\0');
    file.close();
}