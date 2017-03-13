#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  string row;
  int first_beds, consecutive_beds, max_consecutive, max_distance_intermediate;

  while(cin >> row){
    first_beds = 0;
    max_consecutive = 0;
    consecutive_beds = 0;
    while(row[first_beds] == '.')
      first_beds++;
    for(int i = 0; i < row.size(); i++){
      if(row[i] == '.')
        consecutive_beds++;
      else{
        if(max_consecutive < consecutive_beds)
          max_consecutive = consecutive_beds;
        consecutive_beds = 0;
      }
    }

    max_distance_intermediate = max_consecutive /2;
    if(max_consecutive % 2 == 0)
      max_distance_intermediate--;

    cout << max(max_distance_intermediate, max(first_beds-1, consecutive_beds-1)) << endl;
  }


  return 0;
}
