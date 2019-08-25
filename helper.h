#include <string>
#include <vector>

using namespace std;

vector<string> split(string to_split, char delim){
    vector<string> words;
    string curr = "";
    int i;
    for (i = 0; i < to_split.size(); i++){
        if (to_split[i] == delim){
            words.push_back(curr);
            curr = "";
        } else {
            curr += to_split[i];
        }
    }
    if (curr.size()){
        words.push_back(curr);
    }
    return words;
}
