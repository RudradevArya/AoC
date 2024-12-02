
#include <iostream>
//#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

#include <cctype>
#include <fstream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //file opener
    ifstream inp("input1a.txt");

    // Check if the file is open
    if(!inp.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;  // Return an error code
    }

    char first = '\0';
    char last = '\0';
    int final = 0;
    //vector <int> final;
    
    //file reader
    string line;
    while(getline(inp, line))
    {
        //cout<<"Line: "<<line<<endl;
        for (char c : line) {
            //cout<<c<<" ";   
            if(isdigit(c)) 
            {
                first = c;
                break;
            }
            
        }

        // bool foundfirst = (first != '\0');
        // for(char c : line)
        // {
        //     if(foundfirst && isdigit(c))
        //     {
        //         second = c;
        //         break;
        //     }
        // }
        
        for (int i = line.length() - 1; i >= 0; --i) 
        {
            if (isdigit(line[i])) {
                last = line[i];
                break;
            }
        }


        if(first != '\0' || last != '\0')
        {
            int sum=0;
    
            if (first != '\0') {
                sum += (first - '0') * 10;
            }
            if (last != '\0') {
                sum += last - '0';
            }

            final += sum;
        }
    }

    cout<<final;
    // close file
    inp.close();
    return 0;
}

// ans of day 1a = 55447