#include <iostream>
#include <cstring>
#include <memory>
#include <bitset>
#include <sstream>
#include <string>
#include "include/CodeWord.h"
#include "include/DecodeWord.h"

int main() {

    auto Code = std::make_shared<CodeWord>();
    auto Decode = std::make_shared<DecodeWord>();
    //std::cout<<Code->code('a',10);
    std::cout<<Decode->decode("011000010110001011");
    system("pause");
    return 0;
}
