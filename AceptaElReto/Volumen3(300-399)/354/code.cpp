#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  int people, tmp, p, max_kid, min_adult;
  vector<int> heights;

  while(cin >> people && people){
    heights.clear();

    for(int i = 0; i < people; i++){
      cin >> tmp;
      heights.push_back(tmp);
    }

    max_kid = heights[0];
    min_adult = *min_element(heights.begin()+1, heights.end());
    for(p = 1; p < people; p++){
      if(heights[p-1] > max_kid)
        max_kid = heights[p-1];
      if(heights[p-1] == min_adult)
        min_adult = *min_element(heights.begin()+p, heights.end());

      if(max_kid < min_adult)
        break;
    }

    cout << p << '\n';
  }


  return 0;
}
