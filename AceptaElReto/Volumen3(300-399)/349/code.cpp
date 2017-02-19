#include <iostream>
#include <stack>

#define endl        '\n'

using namespace std;

int main(){

  int cases, a, b;
  string line;
  stack<int> op;

  cin >> cases;
  cin.ignore();
  while(cases--){
    getline(cin, line);
    while(!op.empty())
      op.pop();

    for(int i = line.size()-1; i >= 0; i -= 2){
      if(line[i] == '+'){
        a = op.top();
        op.pop();
        b = op.top();
        op.pop();
        op.push(a + b);
      }
      else if(line[i] == '-'){
        a = op.top();
        op.pop();
        b = op.top();
        op.pop();
        op.push(a - b);
      }
      else if(line[i] == '*'){
        a = op.top();
        op.pop();
        b = op.top();
        op.pop();
        op.push(a * b);
      }
      else if(line[i] == '/'){
        a = op.top();
        op.pop();
        b = op.top();
        op.pop();
        op.push(a / b);
      }
      else{
        op.push(line[i] - '0');
      }
    }
    cout << op.top() << endl;
  }

  return 0;
}
