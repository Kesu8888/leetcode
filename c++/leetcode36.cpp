//
// Created by Kesu Peterill on 6/3/2024.
//
#include "all.h"

class leetcode36 {
public:
    bool sol(vector<vector<char>>& board) {
        vector<set<char>*> row;
        vector<set<char>*> column;
        for (int i = 0; i < 9; i++) {
            row.push_back(new set<char>);
            column.push_back(new set<char>);
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> matrix;
                int rowNO = i;
                int columnNO = j;
                while (rowNO < i + 3) {
                    while (columnNO < j + 3) {
                        char c = board.at(rowNO).at(columnNO);
                        if (c != '.') {
                            if (row.at(rowNO)->count(c) || column.at(columnNO)->count(c) || matrix.count(c)) {
                                return false;
                            }
                            row.at(rowNO)->insert(c);
                            column.at(columnNO)->insert(c);
                            matrix.insert(c);
                        }
                        columnNO ++;
                    }
                    columnNO = columnNO - 3;
                    rowNO ++;
                }
            }
        }
        return true;
    }
};