#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class DataFrame {
public:
    vector<vector<double>> data;
    vector<string> columnNames;

    DataFrame() {}

    void read_csv(string filename) {
        ifstream file(filename);
        string line;
        bool isHeader = true;

        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            vector<double> row;
            if (isHeader) {
                isHeader = false;
                while (getline(ss, cell, ',')) {
                    columnNames.push_back(cell);
                }
            } else {
                while (getline(ss, cell, ',')) {
                    row.push_back(stod(cell));
                }
                data.push_back(row);
            }
        }
    }
};

#endif
