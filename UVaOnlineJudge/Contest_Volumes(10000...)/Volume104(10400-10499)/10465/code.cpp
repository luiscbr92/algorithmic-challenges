#include <iostream>

using namespace std;

int main(){

  int m, n, t;

  while(cin >> m >> n >> t){
    int hamburguers[3][t+1];
    int beers[3][t+1];
    int tmp[3] = {0, max(m, n), min(m, n)};

    for(int i = 0; i <= t; i++){
      hamburguers[0][i] = 0;
      beers[0][i] = i;
    }
    hamburguers[1][0] = 0;
    beers[1][0] = 0;
    hamburguers[2][0] = 0;
    beers[2][0] = 0;

    for(int i = 1; i < 3; i++){
      for(int j = 1; j <= t; j++){
        if(j < tmp[i] || beers[i-1][j] < beers[i][j-tmp[i]]){
          hamburguers[i][j] = hamburguers[i-1][j];
          beers[i][j] = beers[i-1][j];
        }
        else if(beers[i-1][j] == beers[i][j-tmp[i]]){
          hamburguers[i][j] = max(hamburguers[i][j-tmp[i]] + 1, hamburguers[i-1][j]);
          beers[i][j] = beers[i-1][j];
        }
        else{
          hamburguers[i][j] = 1 + hamburguers[i][j-tmp[i]];
          beers[i][j] = beers[i][j-tmp[i]];
        }
      }
    }

    /*cout << "**** hamburguers/beers\n";
    for(int i = 0; i < 3; i++){
      for(int j = 0; j <= t; j++){
        cout << hamburguers[i][j] << '/' << beers[i][j] << ' ';
      }
      cout << endl;
    }

    cout << "****" << endl;*/

    cout << hamburguers[2][t];
    if(beers[2][t] != 0)
      cout << ' ' << beers[2][t];
    cout << '\n';
  }

  return 0;
}
