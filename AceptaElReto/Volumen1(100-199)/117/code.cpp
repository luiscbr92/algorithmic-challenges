#include <iostream>
#include <string>

using namespace std;

int main(){

  int num_of_names;
  string line, name;

  cin >> num_of_names;
  cin.ignore();

  while(num_of_names--){
    getline(cin, line);
    name = line.substr(line.find(" ")+1);

    cout << "Hola, " << name << ".\n";
  }

  return 0;
}
