#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "helper.h"

using namespace std;

int main(int argc, char* argv[]){
    string line;
    ifstream f (argv[1]);
    map<string, int> dists;
    vector<string> cities;
    while(getline(f, line)){
        vector<string> words = split(line, ' ');
        dists[words[0] + words[2]] = stoi(words[4]);
        dists[words[2] + words[0]] = stoi(words[4]);
        if (find(cities.begin(), cities.end(), words[0]) == cities.end()){
            cities.push_back(words[0]);
        }
        if (find(cities.begin(), cities.end(), words[2]) == cities.end()){
            cities.push_back(words[2]);
        }
    }

    int shortest_dist = 999999;
    int longest_dist = 0;
    sort(cities.begin(), cities.end());
    do {

        int total = 0;
        for (int i = 0; i < cities.size() - 1; i++){
            total += dists[cities[i] + cities[i+1]];
        }
        if (total < shortest_dist){
            shortest_dist = total;
        } else if (total > longest_dist){
            longest_dist = total;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    cout << "Shortest Distance: " << shortest_dist << "\n";
    cout << "Longest distance: " << longest_dist << "\n";
}
