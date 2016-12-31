#include <iostream>
#include <string>

using namespace std;

int main(){

  int cases;
  string line;
  cin >> cases;
  while(cases--){
    cin >> line;

    int pos = line.find('-');
    string first_str = line.substr(0, pos);
    string second_str = line.substr(pos+1, string::npos);

    int first = stoi(first_str);
    int second = stoi(second_str);
    int a = min(first, second);
    int b = max(first, second);

    if(a == b-1 && a%2 == 0)
      cout << "SI\n";
    else
      cout << "NO\n";
  }


  return 0;
}
