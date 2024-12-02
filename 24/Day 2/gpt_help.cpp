#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

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

    for (int i = 0; i < mat.size(); ++i) {
        bool asc = true, desc = true, validDiff = true;
        for (int j = 1; j < mat[i].size(); ++j) {
            int diff = mat[i][j] - mat[i][j - 1];
            
            // Check valid difference range
            if (abs(diff) < 1 || abs(diff) > 3) {
                validDiff = false;
                break;
            }
            
            // Check ascending and descending conditions
            if (diff > 0) desc = false;
            if (diff < 0) asc = false;
        }
        if ((asc || desc) && validDiff) {
            ++safeCount;
        }
    }

    cout << safeCount << endl;
    return 0;
}
