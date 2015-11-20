#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int h, w;
  int cachos;

  while (cin >> h >> w) {

    if (h == 0 && w == 0)
      break;

    int a, b;
    cin >> a;
    cachos = 0;
    for (int i=1; i<w; i++) {
      cin >> b;
      if (b > a)
        cachos += (b-a);
      a = b;
    }
    cachos+= (h-a);

    cout << cachos << endl;
  }
  return 0;
}
