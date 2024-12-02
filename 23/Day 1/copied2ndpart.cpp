#include <iostream>
#include <bits/stdc++.h>
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

vector<string> read_input() {
	fstream input_file;
	input_file.open("input1a.txt", ios::in);

	vector<string> input;
	if (input_file.is_open()) {
		string line;
		while (getline(input_file, line)) {
			if (!line.empty()) {
				input.push_back(line);
			}
		}
		input_file.close();
	}
	return input;
}

int part1(vector<string>& input) {
	int res = 0;
    for (string line : input) {
        string num = "";
        int i = 0;
        while (true) {
            if (line[i] >= 48 && line[i] <= 57) {
                num += line[i];
                break;
            }
            i++;
        }
        i = line.size() - 1;
        while (true) {
            if (line[i] >= 48 && line[i] <= 57) {
                num += line[i];
                break;
            }
            i--;
        }
        res += stoi(num);
    }
    return res;
}

int part2(vector<string>& input) {
	unordered_map<string, string> hm;
    hm = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };
    vector<string> all_nums = {"one","1","two","2","three","3","four","4","five","5","six","6","seven","7","eight","8","nine","9"};

    int res = 0;
    for (const string& line : input) {
        unordered_map<string, pair<int, int>> location;
        for (string num : all_nums) {
            size_t first_occ = line.find(num);
            if (first_occ != string::npos) {
                location[num].first = first_occ;
            } else {
                location[num].first = -1;
            }

            size_t last_occ = line.rfind(num);
            if (last_occ != string::npos) {
                location[num].second = last_occ;
            } else {
                location[num].second = -1;
            }
        }

        pair<string, int> first_digit = {"", 0};
        pair<string, int> last_digit = {"", 0};
        for (const auto& p : location) {
            if (p.second.first == -1 || p.second.second == -1) {
                continue;
            }
            if (first_digit.first.empty() || p.second.first < first_digit.second) {
                first_digit = {p.first, p.second.first};
            }
            if (last_digit.first.empty() || p.second.second > last_digit.second) {
                last_digit = {p.first, p.second.second};
            }
        }

        string num = "";
        try {
            num += (hm.at(first_digit.first));
        } catch (const out_of_range &e) {
            num += first_digit.first;
        }
        try {
            num += (hm.at(last_digit.first));
        } catch (const out_of_range &e) {
            num += last_digit.first;
        }
        
        res += stoi(num);
        
    }
    return res;
}

int main() {
	vector<string> input = read_input();
    cout << part1(input) << '\n';
	cout << part2(input) << '\n';
	return 0;
}

