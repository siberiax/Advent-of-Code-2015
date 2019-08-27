#include<iostream>

using namespace std;

bool check_abc(string s){

    bool good = false;
    for (int i = 2; i < s.length(); i++){
        if (s[i] == s[i-1] + 1 && s[i-1] == s[i-2] + 1){
            good = true;
            break;
        }
    }
    return good;
}

bool check_aabb(string s){

    int total = 0;
    char seen_char = 'A';
    for (int i = 1; i < s.length(); i++){
        if (s[i] == s[i-1] && s[i] != seen_char){
            seen_char = s[i];
            i++;
            total++;
        }
    }
    return (total >= 2);
}

int main(int argc, char** argv){
    string start = argv[1];

    while(!check_abc(start) || !check_aabb(start)){
        int i = start.length() - 1;
        while(start[i] == 'z'){
            start[i] = 'a';
            i--;
        }
        start[i]++;
    }
    cout << start << "\n";
}
