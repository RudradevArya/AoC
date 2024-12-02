#include <iostream>
//#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ifstream inp("input.txt");

    vector<vector<int>> mat;
    string line;

    while(getline(inp,line)){
        vector<int> l;
        stringstream ss(line);
        int num;

        while(ss >> num){
            l.push_back(num);
        }
        mat.push_back(l);
    }
    
    int n = mat.size(), m = mat[0].size();
    int cnt = 0;

    for(int i=0;i<n;++i){
        bool asc = 1, desc = 1, diff = 1;
        for(int j=1;j<mat[i].size();++j){
            if((mat[i][j] - mat[i][j-1]) < 0){
                asc = 0;
                // break;
            } 
            if((mat[i][j] - mat[i][j-1]) > 0){
                desc = 0;
                // break;
            } 
            if(abs(mat[i][j] - mat[i][j-1]) < 1 
            || abs(mat[i][j] - mat[i][j-1]) > 3
            ){
                diff = 0;
                break;
            }// 1 2 3 4 3 2 1
        }
        if ((asc || desc) && diff) {
            ++cnt;
        }
    }
    cout<<cnt;
    return 0;
}