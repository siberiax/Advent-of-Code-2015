#include <iostream>
#include <fstream>
#include "helper.h"

using namespace std;

class Reindeer
{
    public:
    string name;
    int speed;
    int s_time;
    int rest;
    int points;
    int dist;
    bool active;
    int time_left;
};

int main(int argc, char** argv){
    fstream f (argv[1]);
    string line;
    int furthest = 0;
    vector<Reindeer> deers;
    while(getline(f, line)){
        vector<string> fields = split(line, ' ');
        string name = fields[0];
        int speed = stoi(fields[3]);
        int s_time = stoi(fields[6]);
        int rest = stoi(fields[13]);

        Reindeer r;
        r.name = name;
        r.speed = speed;
        r.s_time = s_time;
        r.rest = rest;
        r.points = 0;
        r.dist = 0;
        r.active = true;
        r.time_left = s_time;


        deers.push_back(r);
    }

    for (int i = 0; i < 2503; i++){

        for (int j = 0; j < deers.size(); j++){
            if (deers[j].active){
                deers[j].dist += deers[j].speed;
                deers[j].time_left--;
                if (deers[j].time_left == 0){
                    deers[j].time_left = deers[j].rest;
                    deers[j].active = false;
                }
            } else {
                deers[j].time_left--;
                if(deers[j].time_left == 0){
                    deers[j].time_left = deers[j].s_time;
                    deers[j].active = true;
                }
            }
        }

        vector<int> winners;
        int best_dist = 0;
        for (int j = 0; j < deers.size(); j++){
            if (deers[j].dist > best_dist){
                best_dist = deers[j].dist;
                winners.clear();
                winners.push_back(j);
            } else if (deers[j].dist == best_dist){
                winners.push_back(j);
            }
        }

        for (int j: winners){
            deers[j].points++;
        }
    }

    int most_points = 0;
    int furthest_dist = 0;
    string best_deer;
    string dist_deer;
    for (Reindeer r: deers){
        if (r.points > most_points){
            most_points = r.points;
            best_deer = r.name;
        }
        if (r.dist > furthest_dist){
            furthest_dist = r.dist;
            dist_deer = r.name;
        }
    }

    cout << dist_deer << ": " << furthest_dist << "km\n";
    cout << best_deer << ": " << most_points << " points\n";
}
