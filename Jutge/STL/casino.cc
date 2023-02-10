#include <iostream>
#include <map>
using namespace std;

void enters(string& name, map<string,int>& cas_map) {
	map<string,int>::iterator it = cas_map.find(name);
	if (it == cas_map.end())
		cas_map.insert(make_pair(name,0));
	else 
		cout << name << " is already in the casino" << endl;
}

void wins(string& name, map<string,int>& cas_map, int x) {
	map<string,int>::iterator it;
	it = cas_map.find(name);
	/*
	if (it != cas_map.end()) {
		int x;
	    cin >> x;
	    it->second += x;
	} else {
		cout << name << " is not in the casino" << endl;
	}
    */
	if (it == cas_map.end()) 
		cout << name << " is not in the casino" << endl;
	else {
		it->second = it->second + x;
	}
}

void leaves(string& name, map<string,int>& cas_map) {
	map<string,int>::iterator it = cas_map.find(name);
	if (it != cas_map.end()) {
		cout << name << " has won " << cas_map[name] << endl;
	    cas_map.erase(name);
	} else {
		cout << name << " is not in the casino" << endl;
	}
	
}

int main() {
    
    map<string,int> cas_map;
	string name, op;

	while (cin >> name >> op) {

	    if (op == "enters") enters(name, cas_map);
	    else if (op == "wins") {
	    	int x;
	    	cin >> x;
	    	wins(name, cas_map, x);
	    }
        else if (op == "leaves") leaves(name, cas_map);
	}
    
    cout << "----------" << endl;

	//write ordered list
	map<string,int>::iterator it;
	for (it = cas_map.begin(); it != cas_map.end(); ++it) {
		cout << it->first << " is winning " << it->second << endl;
	}
}