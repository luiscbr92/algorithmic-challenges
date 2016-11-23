#include <iostream>
#include <string>

using namespace std;

int main(){

  string line;
  int size, pos;
  bool palindrome;

  while(getline(cin, line) && line != "XXX"){
    while((pos = line.find(' ')) != string::npos)
      line.erase(pos,1);
    size = line.size();
    palindrome = true;
    for(int i = 0; i < size/2; i++){
      if(line[i] >= 'A' && line[i] <= 'Z')
        line[i] += 'a' - 'A';

      if(line[size-1-i] >= 'A' && line[size-1-i] <= 'Z')
        line[size-1-i] += 'a' - 'A';

      if(line[i] != line[size-1-i]){
        palindrome = false;
        break;
      }
    }
    if(palindrome)
      cout << "SI\n";
    else
      cout << "NO\n";
  }

  return 0;
}
