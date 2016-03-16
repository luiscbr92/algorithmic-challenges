#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int min_spaces, number_of_rows, i, curr_space, voids;
    string left_surface, right_surface;
    vector<int> spaces;

    while(cin >> number_of_rows && number_of_rows){
        min_spaces = 23;
        spaces.clear();
        voids = 0;
        for(i = 0; i < number_of_rows; i++){
            cin >> left_surface;
            if(left_surface.size() == 25){
                min_spaces = 0;
                spaces.push_back(0);
            }
            else{
                cin >> right_surface;
                curr_space = 25 - left_surface.size() - right_surface.size();
                spaces.push_back(curr_space);
                if(curr_space < min_spaces) min_spaces = curr_space;
            }
        }

        for(i = 0; i < number_of_rows; i++)
            voids += spaces[i] - min_spaces;

        cout << voids << '\n';
    }

    return 0;
}
