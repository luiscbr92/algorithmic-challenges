#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

  int people, relations, stable_groups;
  string name, person1, person2;
  while(cin >> people >> relations && (people || relations)){
    cin.ignore();
    vector<int> tmpvec (people, 0);
    vector<vector<int>> matrix (people, tmpvec);
    map<string, int> name_to_index;
    for(int i = 0; i < people; i++){
      matrix[i][i] = 1;
      getline(cin, name);
      name_to_index.insert(make_pair(name, i));
    }
    for(int i = 0; i < relations; i++){
      getline(cin, person1);
      getline(cin, person2);
      matrix[name_to_index[person1]][name_to_index[person2]] = 1;
    }

    for(int k = 0; k < people; k++)
      for(int i = 0; i < people; i++)
        for(int j = 0; j < people; j++)
          matrix[i][j] = matrix[i][j] || matrix[i][k] && matrix[k][j];

    stable_groups = 0;
    for(int i = 0; i < people; i++){
      if(matrix[i][i] == 1){
        stable_groups++;
        for(int j = i+1; j < people; j++){
          if(matrix[i][j] == 1 && matrix[j][i] == 1)
            matrix[j][j] = 0;
        }
      }
    }

    cout << stable_groups << '\n';
  }

  return 0;
}
