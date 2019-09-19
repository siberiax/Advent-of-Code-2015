#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>
#include "helper.h"

using namespace std;

int main(int argc, char** argv){

    if (argc < 2){
        cout << "Usage: ./day19 input_file" << "\n";
        return 1;
    }
    fstream f (argv[1]);
    vector< tuple<string, string> > changes;
    string line;
    string word;
    while(getline(f, line)){
        vector<string> fields = split(line, ' ');
        if (fields.size() == 1){
            word = fields[0];
        } else {
            tuple<string, string> pair;
            pair = make_tuple(fields[0],fields[2]);
            changes.push_back(pair);
        }
    }
    set<string> combos;
    for (auto change: changes){

        string old_s = get<0>(change);
        string new_s = get<1>(change);

        int index = word.find(old_s);
        while(index != string::npos){
            string combo = word.substr(0, index) + new_s + word.substr(index + old_s.size());
            combos.insert(combo);
            index = word.find(old_s, index+1);
        }
    }
    cout << combos.size() << "\n";

    //part 2

    set<string> options;
    options.insert(word);

    int depth = 1;
    while(1){
        cout << options.size() <<  "\n";
        set<string> new_options;
        for (auto option: options){
            for (auto change: changes){
                string old_s = get<1>(change);
                string new_s = get<0>(change);

                int index = option.find(old_s);
                while(index != string::npos){
                    string combo = option.substr(0, index) + new_s + option.substr(index + old_s.size());
                    if (combo.compare("e") == 0){
                        cout << depth << "\n";
                        return 1;
                    }
                    new_options.insert(combo);
                    index = option.find(old_s, index+1);
                }
            }
        }
        options = new_options;
        depth++;
    }
}
