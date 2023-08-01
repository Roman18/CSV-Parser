#include "CSV.hpp"

#include <iostream>

    csv::CSVReader::CSVReader(std::string fileName) : fileName(fileName){
        initOpenFile();
    }

    void csv::CSVReader::initOpenFile(){
        this->f.open(this->fileName);
        if(!this->f.is_open())
            throw std::invalid_argument("Cannot open file "+this->fileName);
    };

    

    
    std::vector<std::string> csv::CSVReader::readLine(){
        if(!this->f.is_open())
            throw std::invalid_argument("Cannot read from file "+ this->fileName);

        std::vector<std::string> res;
        std::string line {};


        if(!this->f.eof()){
            std::getline(this->f, line);

            res = parseLine(line);
        }

        return res;

    }
    std::vector<std::vector<std::string>> csv::CSVReader::readLines(){
        std::vector<std::vector<std::string>> res;

        while(!this->f.eof()){
            res.push_back(this->readLine());
        }

        this->close();

        return res;
    }

    std::vector<std::string> csv::CSVReader::parseLine(std::string line){ // TODO: improve function
        std::vector <std::string> res;
        std::string tmp{};
        for(size_t i = 0; i < line.size(); ++i){

            if(line[i] == ',' || i == line.size() - 1){
                tmp += line[i] == ',' ? '\0' : line[i];
                res.push_back(tmp);
                tmp = "";
            }else{
                tmp += line[i];
            }
        }

        return res;
    }

    void csv::CSVReader::close(){
        this->f.close();
    }

    csv::CSVReader::~CSVReader(){
        this->f.close();
    }