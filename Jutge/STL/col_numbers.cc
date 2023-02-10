#include <iostream>
#include <queue>
using namespace std;

int main() {

	priority_queue<int> pq;
	string w;

	while (cin >> w) {

		if (w == "A") {
			if (pq.empty()) cout << "error!" << endl;
			else cout << pq.top() << endl;

		} else if (w == "S") {
			int x;
			cin >> x;
			pq.push(x);

		} else if (w == "R") {
			if (pq.empty()) cout << "error!" << endl;
			else pq.pop();

		} else if (w == "I") {
			if (pq.empty()) cout << "error!" << endl;
			else {
				int x;
			    cin >> x;
			    int replace = pq.top();
			    pq.pop();
			    replace += x;
			    pq.push(replace);
			}
			

	    } else if (w == "D") {
	    	if (pq.empty()) cout << "error!" << endl;
			else {
				int x;
			    cin >> x;
			    int replace = pq.top();
			    pq.pop();
			    replace -= x;
			    pq.push(replace);
			}
	    }
	}
}