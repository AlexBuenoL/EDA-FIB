#include <iostream>
#include <map>
using namespace std;

int main() {

	map<string,int> bag;
	map<string,int>::iterator it;

	string w;
    while (cin >> w) {

    	if (w == "minimum?") {
    		it = bag.begin();
    		if (it == bag.end()) cout << "indefinite minimum" << endl;
    		else 
    			cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
    	} 
    	else if (w == "maximum?") {
    		it = bag.end();
    		if (bag.size() == 0) cout << "indefinite maximum" << endl;
    		else {
    			--it;
    			cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
    		}

    	} else if (w == "store") {
    		string x;
    		cin >> x;
    		it = bag.find(x);
    		if (it == bag.end()) bag.insert(make_pair(x,1));
    		else ++bag[x];

    	} else if (w == "delete") {
    		string x;
    		cin >> x;
    		it = bag.find(x);
    		if (it != bag.end()) {
    			if (it->second == 1) bag.erase(it);
    		    else --bag[x];
    		}	
    	}
    }
}