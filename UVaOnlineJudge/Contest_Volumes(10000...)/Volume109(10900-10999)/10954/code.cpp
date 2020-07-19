#include <iostream>
#include <queue>

#define endl    '\n'

using namespace std;

int main(){

  int numbers, read_number, a, b;

  while (cin >> numbers && numbers) {

    priority_queue<int, vector<int>, greater<int>> pq;
    int cost = 0;
    for (int i = 0; i < numbers; i++){
      cin >> read_number;
      pq.push(read_number);
    }

    while(pq.size() > 1){
      a = pq.top(); pq.pop();
      b = pq.top(); pq.pop();

      cost += a + b;
      pq.push(a + b);
    }


    cout << cost << endl;

  }

  return 0;
}
