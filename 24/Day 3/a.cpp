#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream inp("input.txt");
    
    // regex pat("(.*)(mul([0-999],[0-999]))(.*)");
    //part 1
    regex pat(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int sum = 0;
    string line;
    while(getline(inp, line)){
        auto beg = sregex_iterator(line.begin(), line.end(), pat);
        auto end = sregex_iterator();

        for(sregex_iterator i = beg; i != end; ++i){
            int prod;
            smatch mat = *i;
            int n1 = stoi(mat[1].str());
            int n2 = stoi(mat[2].str());
            prod = n1*n2;
            sum += prod;
        }
    }
    cout<<sum<<endl;

// Reset the file pointer to the beginning of the file for part 2
    inp.clear();
    inp.seekg(0);

    // part 2
    regex pat1(R"(mul\((\d{1,3}),(\d{1,3})\))");
    regex pat2(R"(do\(\))");
    regex pat3(R"(don't\(\))");

    int sum2 = 0;
    string line2;
    bool ena = 1;

    while(getline(inp, line2)){
        auto beg1 = sregex_iterator(line2.begin(), line2.end(), pat1);
        auto end1 = sregex_iterator();

        auto beg2 = sregex_iterator(line2.begin(), line2.end(), pat2);
        auto end2 = sregex_iterator();

        auto beg3 = sregex_iterator(line2.begin(), line2.end(), pat3);
        auto end3 = sregex_iterator();

        for(auto i = beg2; i != end2;++i){
            ena = 1;
        }

        for(auto i = beg3; i != end3;++i){
            ena = 0;
        }

        for(sregex_iterator i = beg1; i != end1; ++i){
            int prod;
            smatch mat = *i;
            int n1 = stoi(mat[1].str());
            int n2 = stoi(mat[2].str());
            if(ena){
                prod = n1*n2;
                sum2 += prod;
            }
        }
    }
    cout<<sum2;

    
 
    return 0;
}