#include <iostream>
#include <cstring>
#include <memory>
#include <bitset>
#include <sstream>
#include <string>
#include "include/CodeWord.h"
#include "include/DecodeWord.h"
#include "include/FileService.h"

void printl(char text) {
    std::cout<<text<<std::endl;
}

void printl(std::string text) {
    std::cout<<text<<std::endl;
}


int main() {
    char choice = '1';
    std::stringstream stringstream;
    stringstream<<"Available options:\n"<<"1. Character encoding.\n"
                                        <<"2. Character Decoding.\n"
                                        <<"3. File encoding.\n"
                                        <<"4. File decoding.\n"
                                        <<"5. Exit.\n";
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
            case '5': { //Exit
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
