#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> empty_vector;
vector<vector<int>> adjacency_list;
vector<vector<int>> reverse_adjacency_list;
vector<bool> used;
vector<int> order;

void dfs_for_first_phase(int vertex){
  used[vertex] = true;
  for(int i = 0; i < adjacency_list[vertex].size(); i++)
    if(!used[adjacency_list[vertex][i]])
      dfs_for_first_phase(adjacency_list[vertex][i]);
  order.insert(order.begin(), vertex);
}

void dfs_for_second_phase(int vertex){
  used[vertex] = true;
  for(int i = 0; i < reverse_adjacency_list[vertex].size(); i++)
    if(!used[reverse_adjacency_list[vertex][i]])
      dfs_for_second_phase(reverse_adjacency_list[vertex][i]);
}

int main(){
  int people, relations, stable_groups;
  string name, person1, person2;
  int components;
  while(cin >> people >> relations && (people || relations)){
    cin.ignore();
    map<string, int> name_to_index;
    order.clear();
    used.resize(people);
    adjacency_list.clear();
    reverse_adjacency_list.clear();
    for(int i = 0; i < people; i++){
      adjacency_list.push_back(empty_vector);
      reverse_adjacency_list.push_back(empty_vector);
      getline(cin, name);
      name_to_index.insert(make_pair(name, i));
    }
    for(int i = 0; i < relations; i++){
      getline(cin, person1);
      getline(cin, person2);
      adjacency_list[name_to_index[person1]].push_back(name_to_index[person2]);
      reverse_adjacency_list[name_to_index[person2]].push_back(name_to_index[person1]);
    }

    fill(used.begin(), used.end(), false);
    for(int i = 0; i < people; i++)
      if(!used[i])
        dfs_for_first_phase(i);

    components = 0;
    fill(used.begin(), used.end(), false);
    for(int i = 0; i < people; i++)
      if(!used[order[i]]){
        components++;
        dfs_for_second_phase(order[i]);
      }

    cout << components << '\n';
  }

  return 0;
}
