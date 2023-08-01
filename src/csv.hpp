#ifndef CSV_H_

#include <fstream>
#include <vector>
#include <string>

#define CSV_H_

namespace csv{
    

    class CSVReader{
    private:
        const std::string fileName;
        std::ifstream f;
        std::vector<std::string> parseLine(std::string);
        void initOpenFile();
    public:
        CSVReader(std::string);
        ~CSVReader();
        std::vector<std::string> readLine();
        std::vector<std::vector<std::string>> readLines();
        void close();
    };

    class CSVWriter{
    private:
        const std::string fileName;
        std::ofstream f;
        void initOpenFile();
    public:
        CSVWriter(std::string);
        ~CSVWriter();
        void writeLine(std::vector<std::string>&);
        void writeLines(std::vector<std::vector<std::string>>&);
        void close();
    };
}
#endif // CSV_H_