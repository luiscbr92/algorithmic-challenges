#include <iostream>

using namespace std;

bool esNum(char c) {
  if ((int)c >=48 && (int)c <= 57)
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int cases;
  cin >> cases;
  cin.ignore();
  int puntero;
  string s;
  char c;
  int num;

  for (int i=0; i<cases; i++) {
    cout << "Case " << i+1 << ": ";
    puntero = 0;
    getline(cin, s);
    while (puntero < s.size()) {
      c = s.at(puntero);
      num = 0;
      puntero++;
      while (puntero < s.size() && esNum(s.at(puntero))) {
        num *= 10;
        num += (int)s.at(puntero)-48;
        puntero++;
      }
      for (int k=0; k<num; k++) {
        cout << c;
      }

    }
    cout << endl;
  }

  return 0;
}
