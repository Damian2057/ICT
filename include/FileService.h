//
// Created by Damian on 16.03.2022.
//

#ifndef TELE_COM_FILESERVICE_H
#define TELE_COM_FILESERVICE_H


class FileService {

public:
    char controlToChar(std::string sign);
    std::string convertToArray(std::string twoSigns);
    std::string bitsToString(const std::vector<int> &word);
    void codeFile();
    void deCodeFile();
};


#endif //TELE_COM_FILESERVICE_H
