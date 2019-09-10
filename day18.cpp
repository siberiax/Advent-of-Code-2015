#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void print_grid(vector < vector <int> > grid){
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j <grid[0].size(); j++){
            if (grid[i][j]){
                cout << '#';
            } else {
                cout  << '.';
            }
        }
        cout << "\n";
    }
}

int main(int argc, char** argv){
    string line;
    fstream f (argv[1]);
    vector< vector <int> > grid;
    while(getline(f, line)){
        vector<int> row;
        for (auto c: line){
            c == '#' ? row.push_back(1) : row.push_back(0);
        }
        grid.push_back(row);
    }

    for (int it = 0; it < stoi(argv[2]); it++){
        vector< vector<int> > next = grid;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                int neighbs = 0;
                if (i == 0 && j == 0){
                    // neighbs += grid[i][j+1];
                    // neighbs += grid[i+1][j];
                    // neighbs += grid[i+1][j+1];
                    continue;
                } else if (i == 0 && j == grid[0].size() - 1){
                    // neighbs += grid[i][j-1];
                    // neighbs += grid[i+1][j-1];
                    // neighbs += grid[i+1][j];
                    continue;
                } else if (i == grid.size() - 1 && j == 0){
                    // neighbs += grid[i-1][j];
                    // neighbs += grid[i-1][j+1];
                    // neighbs += grid[i][j+1];
                    continue;
                } else if (i == grid.size() - 1 && j == grid[0].size() - 1){
                    // neighbs += grid[i-1][j-1];
                    // neighbs += grid[i-1][j];
                    // neighbs += grid[i][j-1];
                    continue;
                } else if (i == 0){
                    neighbs += grid[i][j-1];
                    neighbs += grid[i][j+1];
                    neighbs += grid[i+1][j-1];
                    neighbs += grid[i+1][j];
                    neighbs += grid[i+1][j+1];
                } else if (i == grid.size() - 1){
                    neighbs += grid[i-1][j-1];
                    neighbs += grid[i-1][j];
                    neighbs += grid[i-1][j+1];
                    neighbs += grid[i][j-1];
                    neighbs += grid[i][j+1];
                } else if (j == 0){
                    neighbs += grid[i-1][j];
                    neighbs += grid[i-1][j+1];
                    neighbs += grid[i][j+1];
                    neighbs += grid[i+1][j];
                    neighbs += grid[i+1][j+1];
                } else if (j == grid[0].size() - 1){
                    neighbs += grid[i-1][j-1];
                    neighbs += grid[i-1][j];
                    neighbs += grid[i][j-1];
                    neighbs += grid[i+1][j-1];
                    neighbs += grid[i+1][j];
                } else {
                    neighbs += grid[i-1][j-1];
                    neighbs += grid[i-1][j];
                    neighbs += grid[i-1][j+1];
                    neighbs += grid[i][j-1];
                    neighbs += grid[i][j+1];
                    neighbs += grid[i+1][j-1];
                    neighbs += grid[i+1][j];
                    neighbs += grid[i+1][j+1];
                }
                if (grid[i][j] == 1){
                    next[i][j] = neighbs == 2 || neighbs == 3 ? 1 : 0;
                } else {
                    next[i][j] = neighbs == 3 ? 1 : 0;
                }
            }
        }
        grid = next;
    }

    int total = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            total += grid[i][j];
        }
    }
    cout << total << "\n";
}
