#include <iostream>

using namespace std;

int main(){

  int cases, term1, term2, fin, attendance, class1, class2, class3;
  float sum;

  cin >> cases;
  for(int c = 1; c <= cases; c++){
    cout << "Case " << c << ": ";

    cin >> term1 >> term2 >> fin >> attendance >> class1 >> class2 >> class3;
    sum = term1 + term2 + fin + attendance;

    sum += max(class1 + class2, max(class1 + class3, class2 + class3))/2.0;


    if(sum >= 90.0)       cout << "A\n";
    else if(sum >= 80.0)  cout << "B\n";
    else if(sum >= 70.0)  cout << "C\n";
    else if(sum >= 60.0)  cout << "D\n";
    else                  cout << "F\n";
  }

  return 0;
}
