#include <iostream>

using namespace std;

int main(){

  int cases;
  string w;
  int tam;

  cin >> cases;

  for(int c = 1; c <= cases; c++){
    cin >> w;

    tam = w.size();

    int matriz[tam][tam] = {0};

    int diff, begin, end;
    for(diff = 1; diff < tam; diff++){
      begin = 0;
      end = begin + diff;
      while(end < tam){
        if(w[begin] == w[end])
          matriz[begin][end] = matriz[begin+1][end-1];
        else
          matriz[begin][end] = 1 + min(min(matriz[begin+1][end], matriz[begin][end-1]), matriz[begin+1][end-1]);
        begin++;
        end++;
      }
    }

    cout << "Case " << c << ": " << matriz[0][tam-1] << '\n';
  }

  return 0;
}
