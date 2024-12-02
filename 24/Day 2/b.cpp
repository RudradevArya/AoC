// #include <iostream>
// //#include <bits/stdc++.h>
// #include <sstream>
// #include <vector>
// #include <cstdio>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <string>
// #include <fstream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     ifstream inp("input.txt");

//     string line;
//     vector<vector<int>> mat;
//     while(getline(inp, line)){
//         stringstream ss(line);
//         int num;
//         vector<int> l;
//         while(ss>>num){
//             l.push_back(num);
//         }
//         mat.push_back(l);
//     }

//     int n = mat.size();
//     int safeCount=0;

//     for(int i=0;i<n;++i){
//         bool asc = 1, desc = 1, diff = 1;
//         for(int j=1;j<mat[i].size();++j){
//             int d = mat[i][j] - mat[i][j-1];
//             if(d>0) desc = 0;
//             if(d<0) asc = 0;
//             if(abs(d)<1 || abs(d)>3){
//                 diff = 0;
//                 break;
//             }
//             if((asc || desc) && diff){
//                 safeCount++;
//             }
//         }

//         bool dampenerWorks = false;
//         for (int i = 0; i < mat[i].size(); ++i) {
//             bool localAsc = true, localDesc = true, localValidDiff = true;
//             for (int j = 1; j < mat[i].size(); ++j) {
//                 if (j == i) continue;  // Skip the removed element
//                 int prev = (j == 1) ? mat[i][0] : mat[i][j - 1 == i ? j - 2 : j - 1];
//                 int diff = mat[i][j] - prev;

//                 if (abs(diff) < 1 || abs(diff) > 3) {
//                     localValidDiff = false;
//                     break;
//                 }
//                 if (diff > 0) localDesc = false;
//                 if (diff < 0) localAsc = false;
//             }
//             if ((localAsc || localDesc) && localValidDiff) {
//                 dampenerWorks = true;
//                 break;
//             }
//         }

//         if (dampenerWorks) {
//             ++safeCount;
//         }
//     }
//     cout << safeCount << endl;

//     return 0;
// }
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

// Function to check if a given row is safe
bool isSafe(const vector<int>& row) {
    bool asc = true, desc = true;
    for (int j = 1; j < row.size(); ++j) {
        int diff = row[j] - row[j - 1];
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }
        if (diff > 0) desc = false;
        if (diff < 0) asc = false;
    }
    return asc || desc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream inp("input.txt");

    vector<vector<int>> mat;
    string line;

    // Reading input file
    while (getline(inp, line)) {
        vector<int> row;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        mat.push_back(row);
    }

    int safeCount = 0;

    for (const auto& row : mat) {
        // Check if the row is already safe
        if (isSafe(row)) {
            ++safeCount;
            continue;
        }

        // Try removing each element to see if the row becomes safe
        bool dampenerWorks = false;
        for (int i = 0; i < row.size(); ++i) {
            vector<int> modifiedRow = row;
            modifiedRow.erase(modifiedRow.begin() + i);
            if (isSafe(modifiedRow)) {
                dampenerWorks = true;
                break;
            }
        }
        
        if (dampenerWorks) {
            ++safeCount;
        }
    }

    cout << safeCount << endl;
    return 0;
}
