#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Player {
    string name;
    int points;
    bool logged;
};

bool cmp(Player p1, Player p2) {
    if (p1.points != p2.points) return p1.points > p2.points;
    else return p1.name <= p2.name;
}

// PROBLEM: WHEN EXECUTES 'PLAY X Y' AND X, Y ARE NOT LOGGED
int main() {

    unordered_map<string, Player> map_p;

    string op;
    string p1;
    while (cin >> op >> p1) {

        if (op == "LOGIN") {

            unordered_map<string, Player>::iterator it = map_p.find(p1);
            if (it == map_p.end()) {
                Player p;
                
                p.name = p1;
                p.points = 1200;
                p.logged = true;
                
                map_p.insert(make_pair(p1,p));

            } else {
                if (not map_p[p1].logged) map_p[p1].logged = true;
            }

        } else if (op == "LOGOUT") {

            auto it = map_p.find(p1);
            // if p1 in the map -> if p1 logged -> logout
            if (it != map_p.end()) 
                if (map_p[p1].logged) map_p[p1].logged = false;

        } else if (op == "PLAY") {

            string p2;
            cin >> p2;

            auto it = map_p.find(p1);
            auto it2 = map_p.find(p2);

            // if some of them are not in the map...
            if (it == map_p.end() or it2 == map_p.end()) {
                cout << "jugador(s) no connectat(s)" << endl;
            
            // if both are in the map...
            } else {

                if (not map_p[p1].logged or not map_p[p2].logged)
                    cout << "jugador(s) no connectat(s)" << endl;

                else {
                    
                    map_p[p1].points += 10; 
                    map_p[p2].points -= 10;

                    if (map_p[p2].points <= 1200) 
                       map_p[p2].points = 1200;
                }
            }

        } else if (op == "GET_ELO") {

            cout << p1 << ' ' << map_p[p1].points << endl;

        }
    }

    vector<Player> vec(map_p.size());
    auto it = map_p.begin();

    for (int i = 0; i < vec.size(); ++i) {
        vec[i].name = it->first;
        vec[i].points = it->second.points;
        ++it;
    }

    sort(vec.begin(), vec.end(), cmp);

    cout << endl << "RANKING" << endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i].name << ' ' << vec[i].points << endl;
    }
}