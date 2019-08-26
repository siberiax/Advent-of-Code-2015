#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv){
    int iterations = stoi(argv[2]);
    string curr = argv[1];
    for (int i = 0; i < iterations; i++){
        string new_s;

        char curr_c;
        int curr_tot = 0;
        for (int j = 0; j < curr.size(); j++){
            if (j == 0){
                curr_c = curr[j];
            }
            if (curr[j] == curr_c){
                curr_tot++;
            } else {
                new_s += to_string(curr_tot) + curr_c;
                curr_c = curr[j];
                curr_tot = 1;
            }
        }
        new_s += to_string(curr_tot) + curr_c;
        curr = new_s;
    }
    cout << curr.size() << "\n";
}
