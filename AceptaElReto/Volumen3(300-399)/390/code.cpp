#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  long cases, magenta, yellow, cian;
  bool drawable;
  string drawing;

  cin >> cases;
  while(cases--){
    cin >> magenta >> yellow >> cian >> drawing;
    drawable = true;

    for(int i = 0; i < drawing.size(); i++){
      if(drawing[i] == 'B')
        continue;
      else if(drawing[i] == 'M')
        magenta--;
      else if(drawing[i] == 'A')
        yellow--;
      else if(drawing[i] == 'C')
        cian--;
      else if(drawing[i] == 'R'){
        magenta--;
        yellow--;
      }
      else if(drawing[i] == 'V'){
        yellow--;
        cian--;
      }
      else if(drawing[i] == 'L'){
        magenta--;
        cian--;
      }
      else if(drawing[i] == 'N'){
        magenta--;
        yellow--;
        cian--;
      }

      if(magenta < 0 || yellow < 0 || cian < 0){
        drawable = false;
        break;
      }
    }

    if(drawable)
      cout << "SI " << magenta << ' ' << yellow << ' ' << cian << endl;
    else
      cout << "NO" << endl;
  }


  return 0;
}
