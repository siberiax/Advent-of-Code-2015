#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    string input;
    fstream f (argv[1]);
    getline(f, input);

    regex reg("-?\\d+");
    smatch mat;

    int total = 0;
    while (regex_search(input, mat, reg)) {
        total += stoi(mat[0]);
        input = mat.suffix();
    }
    cout << total << "\n";
}
