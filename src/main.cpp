#include "csv.hpp"
#include <iostream>
#include <vector>

using csv::CSVReader;
using csv::CSVWriter;

using namespace std;

void testWriter(){
    vector<string> f{"one", "two,", "th,ree", "fo\"ur"};
    vector<string> s{"five", "six\""};
    vector<string> t{"hello,", "\"amazing\"", "world!", "how", "are \"you\"?"};
    vector<vector<string>> lines{f, s, t};
    try
    {
        CSVWriter *csvW = new CSVWriter("file.csv");
        csvW->writeLines(lines);
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << '\n';
    }
    
    
}

void testReader(){
try{
        CSVReader *csv = new CSVReader("test.csv");
        vector<vector<string>> lines = csv->readLines();
        csv->close();
        for (size_t i = 0; i < lines.size(); ++i){
            for (size_t j = 0; j < lines.at(i).size(); ++j)
            {
                cout << lines.at(i).at(j) << "\t|\t";
            }
            cout << endl;
            
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << '\n';
    }
}


int main(void){

    testReader();
    testWriter();
    
    
    
    
    return 0;
    
    
}