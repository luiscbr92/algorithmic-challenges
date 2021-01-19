#include <iostream>

using namespace std;

int check_baggage(double length, double width, double depth, double weight){
  if(length > 56.00 || width > 45.00 || depth > 25.00)
    return (length + width + depth <= 125.00 && weight <= 7.00);
  return weight <= 7.00;
}

int main(){

  int cases, allowed_bags, allowed_test_result;
  double length, width, depth, weight;

  allowed_bags = 0;
  cin >> cases;
  while(cases--) {
    cin >> length >> width >> depth >> weight;

    allowed_test_result = check_baggage(length, width, depth, weight);
    allowed_bags += allowed_test_result;

    cout << allowed_test_result << endl;
  }

  cout << allowed_bags << endl;

  return 0;
}
