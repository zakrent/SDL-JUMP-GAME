//
// Created by zakrent on 3/9/18.
//

#include "FileParser.h"

FileParser::FileParser(std::string _filename) {
    filename = _filename;
    parseFile();
}

FileParser::~FileParser() {
}

void FileParser::parseFile() {
    file.open(filename);
    std::string key;
    int value = 0;
    while(!file.eof()){
        file>>key;
        file>>value;
        data[key] = value;
        if(file.fail()){
            perror("File parsing failed!");
            exit(-1);
        }
    }
    file.close();
}
