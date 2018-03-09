//
// Created by zakrent on 3/9/18.
//

#ifndef SDL_JUMP_FILEPARSER_H
#define SDL_JUMP_FILEPARSER_H

#include <string>
#include <map>
#include <fstream>

class FileParser {
    std::fstream file;
    std::string filename;
    void parseFile();

public:
    std::map<std::string, int> data;

    explicit FileParser(std::string filename);
    ~FileParser();
};


#endif //SDL_JUMP_FILEPARSER_H
