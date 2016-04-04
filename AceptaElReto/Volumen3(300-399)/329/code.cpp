#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool my_comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    ios_base::sync_with_stdio (false);

    int number_of_buildings, tmp_east, tmp_west, i, j, tunnels;
    vector<pair<int,int>> buildings;
    pair<int,int> tmp_building;

    while(cin >> number_of_buildings && number_of_buildings){
        buildings.clear();
        tunnels = 0;
        
        for(i = 0; i < number_of_buildings; i++){
            cin >> tmp_west >> tmp_east;
            tmp_building = make_pair(tmp_west, tmp_east);
            buildings.push_back(tmp_building);
        }
        sort(buildings.begin(), buildings.end(), my_comp);

        i = 0;
        while(i < number_of_buildings){
            tunnels++;
            j = i;
            while(j < number_of_buildings && buildings[j].first < buildings[i].second) j++;
            i = j;
        }

        cout << tunnels << '\n';
    }

    return 0;
}
