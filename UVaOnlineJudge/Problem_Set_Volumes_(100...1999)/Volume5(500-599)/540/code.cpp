#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <utility>
#include <queue>

using namespace std;

int main(){

  int number_of_teams, number_of_members, member, index_of_team;
  map<int,int> teams_description;
  list<int> team_queue;
  vector<queue<int>> queue_collection;
  int scenario = 1;
  string command;
  queue<int> empty_queue; //always empty

  while(cin >> number_of_teams && number_of_teams){
    cout << "Scenario #" << scenario << '\n';
    scenario++;

    teams_description.clear();
    team_queue.clear();
    queue_collection.clear();

    for(index_of_team = 0; index_of_team < number_of_teams; index_of_team++){
      queue_collection.push_back(empty_queue);
      cin >> number_of_members;
      while(number_of_members--){
        cin >> member;
        teams_description.insert(make_pair(member, index_of_team));
      }
    }

    while(cin >> command && command != "STOP"){
      if(command == "ENQUEUE"){
        cin >> member;
        index_of_team = teams_description[member];

        if(queue_collection[index_of_team].empty()){
          team_queue.push_back(index_of_team);
        }
        queue_collection[index_of_team].push(member);
      }
      else{ // DEQUEUE
        cout << queue_collection[team_queue.front()].front() << '\n';
        queue_collection[team_queue.front()].pop();
        if(queue_collection[team_queue.front()].empty()){
          team_queue.pop_front();
        }
      }
    }
    cout << '\n';
  }

  return 0;
}
