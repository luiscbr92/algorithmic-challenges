#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<queue<int>> platform_b;
stack<int> train;

bool emptyStations(){
    for(int i = 0; i < platform_b.size(); i++){
        if(!platform_b.at(i).empty()) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, n_of_stations, spc_train, spc_b, i, j, tin, n_of_packs, current_station, minutes;
    queue<int> temp;

    // CAUTION: current_station stores the index of platform_b, and de STATION_ID is current_station+1
    cin >> cases;
    for(c = 0; c < cases; c++){
        cin >> n_of_stations >> spc_train >> spc_b;
        platform_b.clear();
        while(!train.empty()) train.pop();

        for(i = 0; i < n_of_stations; i++){
            while(!temp.empty()) temp.pop();
            cin >> n_of_packs;
            for(j = 0; j < n_of_packs; j++){
                cin >> tin;
                temp.push(tin);
            }
            platform_b.push_back(temp);
        }

        current_station = 0;
        minutes = 0;

        while(!emptyStations() || !train.empty()){
            // UNLOAD
            while(!train.empty() && platform_b.at(current_station).size() != spc_b){
                if(train.top() != current_station+1) platform_b.at(current_station).push(train.top());
                train.pop();
                minutes++;
            }

            while(!train.empty() && train.top() == current_station+1){
                train.pop();
                minutes++;
            }

            // LOAD
            while(!platform_b.at(current_station).empty() && train.size() != spc_train){
                train.push(platform_b.at(current_station).front());
                platform_b.at(current_station).pop();
                minutes++;
            }

            current_station++;
            minutes +=2;
            current_station = current_station % n_of_stations;
        }
        cout << minutes-2 << endl;
    }

    return 0;
}
