#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int number_of_buildings, tmp_east, tmp_west, i, j, tunnels;
    vector<int> west;
    vector<int> east;

    while(cin >> number_of_buildings && number_of_buildings){
        vector<bool> connected (number_of_buildings, false);
        west.clear();
        east.clear();
        tunnels = 0;

        for(i = 0; i < number_of_buildings; i++){
            cin >> tmp_west >> tmp_east;
            west.push_back(tmp_west);
            east.push_back(tmp_east);
        }

        for(i = 1; i < number_of_buildings; i++){
            j = i-1;
            tmp_east = east[i];
            tmp_west = west[i];
            while(j >= 0 && east[j] > tmp_east){
                east[j+1] = east[j];
                west[j+1] = west[j];
                j--;
            }
            east[j+1] = tmp_east;
            west[j+1] = tmp_west;
        }

        for(i = 0; i < number_of_buildings; i++){
            if(!connected[i]){
                tunnels++;
                j = i;
                while(j < number_of_buildings && west[j] < east[i]){
                    connected[j] = true;
                    j++;
                }
            }
        }

        cout << tunnels << '\n';
    }

    return 0;
}
