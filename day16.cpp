#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "helper.h"

using namespace std;

int main(int argc, char** argv){

    map<string, int> attribs;

    attribs["children:"] = 3;
    attribs["cats:"] = 7;
    attribs["samoyeds:"] = 2;
    attribs["pomeranians:"] = 3;
    attribs["akitas:"] = 0;
    attribs["vizslas:"] = 0;
    attribs["goldfish:"] = 5;
    attribs["trees:"] = 3;
    attribs["cars:"] = 2;
    attribs["perfumes:"] = 1;

    string line;
    ifstream f (argv[1]);

    while(getline(f, line)){
        vector<string> fields = split(line, ' ');
        map<string, int> curr;
        curr[fields[2]] = stoi(fields[3]);
        curr[fields[4]] = stoi(fields[5]);
        curr[fields[6]] = stoi(fields[7]);

        int hits = 0;
        for (auto kv: curr){
            string key = kv.first;
            int value = kv.second;
            if (key == "cats:" || key == "trees:"){
                if (attribs[key] < value)
                    hits++;
            } else if (key == "pomeranians:" || key == "goldfish:" ){
                if (attribs[key] > value)
                    hits++;
            } else{
                if (attribs[key] == value)
                    hits++;
            }
        }
        if (hits == 3)
            cout << stoi(fields[1]) << "\n";
    }
}
