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
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ifstream inp("input.txt");

    int a,b;
    vector<int> x,y;
    map<int,int> f2;

    while(inp >> a >> b){
        x.push_back(a);
        y.push_back(b);
    }

    for(auto i:y){
        f2[i]++;
    }

    int sum = 0;

    for(int i:x){
        int prod = i * f2[i];
        sum += prod;
    }

    cout<<sum;
}