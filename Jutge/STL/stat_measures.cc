#include <iostream>
#include <queue>
using namespace std;

int main() {

	cout.setf(ios::fixed);
    cout.precision(4);

	priority_queue<int,vector<int>,greater<int> > pq;
	int min, max, sum;

	string op;
	while (cin >> op) {

		if (op == "number") {
			int num;
			cin >> num;
			if (pq.empty()) {
				min = max = sum = num;
			} else {
				if (num < min) min = num;
				else if (num > max) max = num;
				sum += num;
			}
			pq.push(num);
			double avg = double(sum)/pq.size();
			cout << "minimum: " << min;
			cout << ", maximum: " << max;
			cout << ", average: " << avg << endl;

		} else {

			if (not pq.empty()) {

				if (pq.size() == 1) {
					sum = max = min = 0;
					pq.pop();
					cout << "no elements" << endl;

				} else {
					sum -= pq.top();
					pq.pop();
					min = pq.top();
					double avg = double(sum)/pq.size();
			        cout << "minimum: " << min;
			        cout << ", maximum: " << max;
			        cout << ", average: " << avg << endl;
				}
			}
			else {
				cout << "no elements" << endl;
			}
		}
    }
}