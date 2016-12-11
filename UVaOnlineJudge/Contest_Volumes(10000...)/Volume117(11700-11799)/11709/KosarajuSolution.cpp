#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> adjacency_list;
vector<vector<int>> reverse_adjacency_list;
vector<bool> used;
vector<int> order;

void dfs(int vertex, bool in_reverse_graph){
  if(in_reverse_graph == false){
    used[vertex] = true;
    for(int i = 0; i < adjacency_list[vertex].size(); i++)
      if(!used[adjacency_list[vertex][i]])
        dfs(adjacency_list[vertex][i], false);
    order.insert(order.begin(), vertex);
  }
  else{
    used[vertex] = true;
    for(int i = 0; i < reverse_adjacency_list[vertex].size(); i++)
      if(!used[reverse_adjacency_list[vertex][i]])
        dfs(reverse_adjacency_list[vertex][i], true);
  }
}

int main(){
  int people, relations, stable_groups;
  string name, person1, person2;
  int components;
  vector<int> empty_vector;
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
        dfs(i, false);

    components = 0;
    fill(used.begin(), used.end(), false);
    for(int i = 0; i < people; i++)
      if(!used[order[i]]){
        components++;
        dfs(order[i], true);
      }

    cout << components << '\n';
  }

  return 0;
}
