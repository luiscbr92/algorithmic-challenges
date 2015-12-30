#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int length, minimum_distance, i, last_restaurant, last_drugstore, current_distance;
    bool is_first_restaturant, is_first_drugstore;
    string highway;

    while(cin >> length && length != 0){
        cin >> highway;
        minimum_distance = length -1;
        is_first_restaturant = true;
        is_first_drugstore = true;
        for(i = 0; i < length; i++){
            if(highway[i] == 'Z'){
                minimum_distance = 0;
                break;
            }
            if(minimum_distance != 1){
                if(highway[i] == 'R'){
                    last_restaurant = i;
                    if(!is_first_drugstore){
                        current_distance = i - last_drugstore;
                        if(current_distance < minimum_distance) minimum_distance = current_distance;
                    }
                    is_first_restaturant = false;
                }
                else if(highway[i] == 'D'){
                    last_drugstore = i;
                    if(!is_first_restaturant){
                        current_distance = i - last_restaurant;
                        if(current_distance < minimum_distance) minimum_distance = current_distance;
                    }
                    is_first_drugstore = false;
                }
            }
        }
        cout << minimum_distance << "\n";
    }

    return 0;
}
