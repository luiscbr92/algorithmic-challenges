#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

bool my_comp(pair<int,int> a, pair<int,int> b){
  return a.first > b.first;
}

int main(){

  int cases, number_of_coordinates, x, y, highest;
  double sunny_lenght, m, n, proyection_x, x_distance, y_distance;
  vector<pair<int,int>> points;

  cout << fixed;
  cout << setprecision(2);

  cin >> cases;
  while(cases--){
    cin >> number_of_coordinates;
    points.clear();
    for(int i = 0; i < number_of_coordinates; i++){
      cin >> x >> y;
      points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end(), my_comp);

    highest = 0;
    sunny_lenght = 0;
    for(int i = 1; i < number_of_coordinates; i++){
      if(points[i].second > highest){
        m = (points[i].second - points[i-1].second)*1.0 / (points[i].first - points[i-1].first);
        n = points[i-1].second + (points[i-1].second - points[i].second)*1.0 / (points[i].first - points[i-1].first) * points[i-1].first;
        proyection_x = (highest - n) / m;
        x_distance = points[i].first - proyection_x;
        y_distance = points[i].second - highest;
        sunny_lenght += sqrt(x_distance*x_distance + y_distance*y_distance);
        highest = points[i].second;
      }
    }
    cout << sunny_lenght << '\n';
  }

  return 0;
}
