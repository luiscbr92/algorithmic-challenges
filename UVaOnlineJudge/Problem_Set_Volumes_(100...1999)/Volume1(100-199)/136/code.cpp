#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio (false);

	priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> q;
	q.push(1);

	for (int i=0; i<1499; i++) {
		if (q.top()%5 != 0 && q.top()%3 != 0)
			q.push(q.top()*2);
		if (q.top()%5 != 0)
			q.push(q.top()*3);
		q.push(q.top()*5);

		q.pop();
	}
	cout << "The 1500'th ugly number is " << q.top() << "." << endl;
	return 0;
}
