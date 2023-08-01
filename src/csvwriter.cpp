#include "csv.hpp"
#include <iostream>

    csv::CSVWriter::CSVWriter(std::string fileName): fileName(fileName){
        initOpenFile();
    };

    void csv::CSVWriter::initOpenFile(){
        this->f.open(this->fileName);
        if(!this->f.is_open()){
            throw std::invalid_argument("Cannot open file: "+ this->fileName);
        }
    }
    
    void csv::CSVWriter::writeLine(std::vector<std::string> &line){
        if(this->f.is_open()){

            std::string tmp;
            for (size_t i = 0; i < line.size(); i++){
                if(line[i].find(',') != std::string::npos ||
                    line[i].find('"') != std::string::npos){
                    tmp += "\"" + line[i] + "\"";
                }else{
                    tmp += line[i];
                }
                if(i != line.size() - 1)
                    tmp += ",";
                else
                    tmp += "\n";
                
            }
            this->f << tmp;
            this->f.flush();
            
        }else{
            throw std::invalid_argument("Cannot write to file "+ this->fileName);
        }
    }

    void csv::CSVWriter::writeLines(std::vector<std::vector<std::string>> &lines){
        if(this->f.is_open()){
            for (auto &line: lines){
                this->writeLine(line);
            }
        }
    }

    void csv::CSVWriter::close(){
        this->f.close();
    }

    csv::CSVWriter::~CSVWriter(){
        this->f.close();
    };

   