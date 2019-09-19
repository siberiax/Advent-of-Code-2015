#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

    if (argc < 2){
        cout << "Usage: ./day20 number" << "\n";
    }

    int goal = stoi(argv[1]);

    int start = 0;
    int total = 0;
    int curr = 0;
    while(total < goal){
        if (curr % 50 == 0){
            start++;
        }
        total = 0;
        curr++;
        double sq = sqrt(curr);
        for(int i = 1; i <= sq; i++){
            if (curr % i == 0){
                if (i > start){
                    total += i * 11;
                }
                if (curr/i != i){
                    if (curr/i > start){
                        total += (curr/i) * 11;
                    }
                }
            }
        }
    }
    cout << curr << "\n";
}
