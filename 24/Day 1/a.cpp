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

    vector<int> a1;
    vector<int> b1;
    int a,b;
    while(inp>>a>>b){
        // int a,b;
        // inp>>a>>b;
        a1.push_back(a);
        b1.push_back(b);
    }

    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());

    int n = a1.size();
    int sum = 0;

    for(int i=0;i<n;++i){
        sum += abs(a1[i] - b1[i]);
    }
    cout<<sum;
    return 0;
}