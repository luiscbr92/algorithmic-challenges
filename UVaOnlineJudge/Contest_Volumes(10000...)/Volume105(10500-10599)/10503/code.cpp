#include <iostream>
#include <vector>

using namespace std;

bool has_solution(int left, int right, vector<pair<int,int>> pieces, vector<bool> used, int remaining_spaces){
  if(remaining_spaces == 1){
    for(int i = 0; i < pieces.size(); i++){
      if(!used[i]){
        if(pieces[i].first == left && pieces[i].second == right)
          return true;
        else if(pieces[i].second == left && pieces[i].first == right)
          return true;
      }
    }
    return false;
  }

  else if(remaining_spaces > 1){
    for(int i = 0; i < pieces.size(); i++){
      if(!used[i]){
        if(pieces[i].first == left){
          used[i] = true;
          if(has_solution(pieces[i].second, right, pieces, used, remaining_spaces-1))
            return true;
        }
        else if(pieces[i].second == left){
          used[i] = true;
          if(has_solution(pieces[i].first, right, pieces, used, remaining_spaces-1))
            return true;
        }
      }
    }
  }
  return false;
}

int main(){

  int spc_req, n_pieces, i1, i2, d1, d2, p1, p2;
  vector<pair<int,int>> pieces;

  while(cin >> spc_req && spc_req){
    pieces.clear();
    cin >> n_pieces >> i1 >> i2 >> d1 >> d2;

    vector<bool> used (n_pieces, false);
    for(int i = 0; i < n_pieces; i++){
      cin >> p1 >> p2;
      pieces.push_back(make_pair(p1, p2));
    }

    if(has_solution(i2, d1, pieces, used, spc_req))
      cout << "YES\n";
    else
      cout << "NO\n";
  }


  return 0;
}
