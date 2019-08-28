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
    map<string, int> happiness;
    vector<string> people;
    while(getline(f, line)){
        vector<string> words = split(line, ' ');
        int points = stoi(words[3]);
        string second_person = words[10].substr(0, words[10].size()-1);
        if (words[2] == "lose"){
            points *= -1;
        }
        happiness[words[0] + second_person] = points;
        if (find(people.begin(), people.end(), words[0]) == people.end()){
            people.push_back(words[0]);
        }
    }

    //part 2
    for (auto person: people){
        happiness[person + "you"] = 0;
        happiness["you" + person] = 0;
    }

    people.push_back("you");

    int max_happiness = 0;
    sort(people.begin(), people.end());
    do {

        int total = 0;
        for (int i = 0; i < people.size(); i++){
            if (i == 0){
                total += happiness[people[i] + people[i+1]];
                total += happiness[people[i] + people[people.size()-1]];
            } else if (i == people.size() - 1){
                total += happiness[people[i] + people[i-1]];
                total += happiness[people[i] + people[0]];
            } else {
                total += happiness[people[i] + people[i+1]];
                total += happiness[people[i] + people[i-1]];
            }
        }
        if (total > max_happiness){
            max_happiness = total;
        }

    } while (next_permutation(people.begin(), people.end()));

    cout << "Max Happiness: " << max_happiness << "\n";
}
