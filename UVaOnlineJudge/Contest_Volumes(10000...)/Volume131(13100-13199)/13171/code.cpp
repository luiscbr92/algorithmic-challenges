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
      if(drawing[i] == 'W')
        continue;
      else if(drawing[i] == 'M')
        magenta--;
      else if(drawing[i] == 'Y')
        yellow--;
      else if(drawing[i] == 'C')
        cian--;
      else if(drawing[i] == 'R'){
        magenta--;
        yellow--;
      }
      else if(drawing[i] == 'G'){
        yellow--;
        cian--;
      }
      else if(drawing[i] == 'V'){
        magenta--;
        cian--;
      }
      else if(drawing[i] == 'B'){
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
      cout << "YES " << magenta << ' ' << yellow << ' ' << cian << endl;
    else
      cout << "NO" << endl;
  }


  return 0;
}
