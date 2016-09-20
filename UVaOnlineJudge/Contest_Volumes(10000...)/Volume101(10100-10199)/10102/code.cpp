#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int manhattan(int x1, int y1, int x2, int y2){
  int x_distance = x1 - x2;
  int y_distance = y1 - y2;

  if(x_distance < 0)
    x_distance *= -1;
  if(y_distance < 0)
    y_distance *= -1;

  return x_distance + y_distance;
}

int main(){

  int size, min_distance, distance, partial_min_distance;
  string line;
  vector<pair<int,int>> ones;
  vector<pair<int,int>> threes;

  while(cin >> size){
    ones.clear();
    threes.clear();
    for(int i=0; i<size; i++){
      cin >> line;
      for(int j=0; j<size; j++){
        if(line[j] == '1'){
          ones.push_back(make_pair(i,j));
        }
        else if(line[j] == '3'){
          threes.push_back(make_pair(i,j));
        }
      }
    }

    min_distance = 0;
    for(int i = 0; i < ones.size(); i++){
      partial_min_distance = size * 2 - 2;
      for(int j = 0; j < threes.size(); j++){
        distance = manhattan(ones[i].first, ones[i].second, threes[j].first, threes[j].second);
        if(partial_min_distance > distance)
          partial_min_distance = distance;
      }
      if(min_distance < partial_min_distance)
        min_distance = partial_min_distance;
    }

    cout << min_distance << '\n';
  }

  return 0;
}
