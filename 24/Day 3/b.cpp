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


    // part 2
    // regex pat1(R"(mul\((\d{1,3}),(\d{1,3})\))");
    // regex pat2(R"(do\(\))");
    // regex pat3(R"(don't\(\))");
    regex pat(R"((mul\((\d{1,3}),(\d{1,3})\))|(do\(\))|(don't\(\)))");

    int sum2 = 0;
    string line2;
    bool ena = 1;

    while(getline(inp, line2)){
        auto beg = sregex_iterator(line2.begin(), line2.end(), pat);
        auto end = sregex_iterator();

        // auto beg2 = sregex_iterator(line2.begin(), line2.end(), pat2);
        // auto end2 = sregex_iterator();

        // auto beg3 = sregex_iterator(line2.begin(), line2.end(), pat3);
        // auto end3 = sregex_iterator();

        // for(auto i = beg2; i != end2;++i){
        //     ena = 1;
        // }

        // for(auto i = beg3; i != end3;++i){
        //     ena = 0;
        // }

        for(sregex_iterator i = beg; i != end; ++i){
            int prod;
            smatch mat = *i;

            if(mat[1].matched){
                int n1 = stoi(mat[2].str());
                int n2 = stoi(mat[3].str());
                if(ena){
                    prod = n1*n2;
                    sum2 += prod;
                }
            }
            else if(mat[4].matched){
                ena = 1;
            }
            else if(mat[5].matched){
                ena = 0;
            }
        }
    }
    cout<<sum2;

    
 
    return 0;
}