#include <iostream>
#include <cstring>
#include <memory>
#include <bitset>
#include <sstream>
#include <string>
#include "include/CodeWord.h"
#include "include/DecodeWord.h"
#include "include/FileService.h"
#include "include/Matrix.h"
#include "include/FileFactory.h"

void printl(char text) {
    std::cout<<text<<std::endl;
}

void printl(std::string text) {
    std::cout<<text<<std::endl;
}

void printl(int text) {
    std::cout<<text<<std::endl;
}

void print(std::string text) {
    std::cout<<text;
}

//Test Zone
void singleCorrection();
void doubleCorrection();
void repairsingleByte(char i, int& correct, int& mistakes);
void repairdoubleeByte(char sign, int& correct, int& mistakes);
int changeSingleBit(char bit);

int main() {

    char choice = '1';
    std::stringstream stringstream;
    stringstream<<"Available options:\n"<<"1. Character encoding.\n"
                                        <<"2. Character Decoding.\n"
                                        <<"3. File encoding.\n"
                                        <<"4. File decoding.\n"
                                        <<"5 Debug Zone.\n"
                                        <<"6. Exit.\n";
    printl(stringstream.str());
    bool flag = true;
    while (flag) {
        printl("Select options:");
        std::cin>>choice;
        switch (choice) {
            case '1': {
                auto Code = std::make_shared<CodeWord>();
                char sign = 'a';
                printl("Enter a character:");
                std::cin>>sign;
                printl(Code->code(sign,10));
                break;
            }
            case '2': {
                auto Decode = std::make_shared<DecodeWord>();
                std::string biteArray;
                printl("Enter a sequence of 18 bits:");
                std::cin>>biteArray;
                printl(Decode->decode(biteArray));
                break;
            }
            case '3': {
                auto files = std::make_shared<FileService>();
                files->codeFile();
                printl("The contents of the file have been encoded");
                break;
            }
            case '4': {
                auto files = std::make_shared<FileService>();
                files->deCodeFile();
                printl("The contents of the file have been decoded");
                break;
            }
            case '5': {
                singleCorrection();
                doubleCorrection();
                break;
            }
            case '6': { //Exit
                flag = false;
                break;
            }
            default: {
                printl("Wrong type");
            }
        }

    }
    system("pause");
    return 0;
}

void singleCorrection() {
    printl("-------------------------------");
    printl("Single Error Correction");
    int mistakes = 0;
    int correct = 0;
    for (int i = 1; i < 128; ++i) {
        repairsingleByte((char) i, correct, mistakes);
    }

    printl("The number of correct ones");
    printl(correct);
    printl("The number of errors");
    printl(mistakes);
    printl("-------------------------------");
}

void doubleCorrection() {
    printl("-------------------------------");
    printl("Double Error Correction");
    int mistakes = 0;
    int correct = 0;
    for (int i = 1; i < 128; ++i) {
        repairdoubleeByte((char) i, correct, mistakes);
    }

    printl("The number of correct ones");
    printl(correct);
    printl("The number of errors");
    printl(mistakes);
    printl("-------------------------------");
}


void repairsingleByte(char sign, int& correct, int& mistakes) {
    auto Code = std::make_shared<CodeWord>();
    auto Decode = std::make_shared<DecodeWord>();
    auto temp = Code->code(sign,10);
    temp[2] = changeSingleBit(temp[2]);

    if(Decode->decode(temp) == sign) {
        correct++;
    } else {
        mistakes++;
    }
}

void repairdoubleeByte(char sign, int& correct, int& mistakes) {
    auto Code = std::make_shared<CodeWord>();
    auto Decode = std::make_shared<DecodeWord>();
    auto temp = Code->code(sign,10);
    temp[4] = changeSingleBit(temp[4]);
    temp[4] = changeSingleBit(temp[4]);

    if(Decode->decode(temp) == sign) {
        correct++;
    } else {
        mistakes++;
    }
}

int changeSingleBit(char bit) {
    if (bit == '0') {
        return '1';
    } else {
        return '0';
    }
}
