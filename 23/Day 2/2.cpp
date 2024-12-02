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
// #include <unordered_map>


// bool calci()
// {

// }



// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);


//     return 0;
// }

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool isPossible(const std::vector<std::vector<std::string>>& game, const std::unordered_map<std::string, int>& targetCounts) {
    std::unordered_map<std::string, int> counts{{"red", 0}, {"green", 0}, {"blue", 0}};
    
    for (const auto& subset : game) {
        for (const auto& cube : subset) {
            std::istringstream iss(cube);
            std::string color;
            int count;
            iss >> count >> color;

            if (counts.find(color) != counts.end()) {
                counts[color] += count;
            }
        }
    }

    for (const auto& colorCount : counts) {
        if (colorCount.second > targetCounts.at(colorCount.first)) {
            return false;
        }
    }

    return true;
}

std::vector<int> possibleGames(const std::vector<std::string>& input, const std::unordered_map<std::string, int>& targetCounts) {
    std::vector<int> possibleGameIds;

    for (const auto& line : input) {
        std::istringstream iss(line);
        std::string gameIdStr, gameData;
        iss >> gameIdStr >> gameData;

        int gameId = std::stoi(gameIdStr.substr(0, gameIdStr.size() - 1));  // Remove the colon from the gameId
        std::istringstream gameDataStream(gameData);
        std::vector<std::vector<std::string>> subsets;
        std::string subsetStr;

        while (std::getline(gameDataStream, subsetStr, ';')) {
            std::istringstream subsetStream(subsetStr);
            std::vector<std::string> subset;
            std::string cube;

            while (subsetStream >> cube) {
                subset.push_back(cube);
            }

            subsets.push_back(subset);
        }

        if (isPossible(subsets, targetCounts)) {
            possibleGameIds.push_back(gameId);
        }
    }

    return possibleGameIds;
}

int main() {
    // Example input data
    std::ifstream inputFile("input.txt");
    std::vector<std::string> input;
    std::string line;

    // while (std::getline(inputFile, line)) {
    //     input.push_back(line);
    // }

      while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string gameIdStr, gameData;
        iss >> gameIdStr >> gameData;

        // Check if the gameIdStr is a valid integer
        if (!gameIdStr.empty() && std::all_of(gameIdStr.begin(), gameIdStr.end(), ::isdigit)) {
            int gameId = std::stoi(gameIdStr);
            std::istringstream gameDataStream(gameData);

            // Rest of the code remains the same...
        } else {
            std::cerr << "Error: Invalid gameId - " << gameIdStr << std::endl;
        }
    }

    // Target cube counts
    std::unordered_map<std::string, int> targetCounts{{"red", 12}, {"green", 13}, {"blue", 14}};

    // Find possible games
    std::vector<int> possibleGameIds = possibleGames(input, targetCounts);

    // Calculate the sum of IDs
    int sumOfIds = 0;

    for (int gameId : possibleGameIds) {
        sumOfIds += gameId;
    }

    std::cout << "The sum of the IDs of the possible games is: " << sumOfIds << std::endl;

    return 0;
}
