
//
// Created by Damian on 15.03.2022.
//

#ifndef TELE_COM_FILEFACTORY_H
#define TELE_COM_FILEFACTORY_H

#include <string>

class FileFactory {

private:
    std::string text;

public:
    std::string getText();
    void readFileToText(const std::string& input);
    void saveFile(const std::string& textToSave, const std::string& output);
    std::string getLineFromFile(int &index, std::string &text);


};


#endif //TELE_COM_FILEFACTORY_H
