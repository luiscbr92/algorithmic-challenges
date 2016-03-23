#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<int> diameters;
    string input;
    int space_pos, i, j, max_diameter, max_pos;

    while(getline(cin, input)){
        diameters.clear();
        cout << input << '\n';

        while(input != ""){
            if((space_pos = input.find(' ')) != string::npos){
                diameters.insert(diameters.begin(), stoi(input.substr(0,space_pos)));
                input = input.substr(space_pos+1);
            }
            else{
                diameters.insert(diameters.begin(), stoi(input));
                input = "";
            }
        }

        for(i = 0; i < diameters.size(); i++){
            max_diameter = diameters[i];
            max_pos = i;
            for(j = i+1; j < diameters.size(); j++){
                if(max_diameter <= diameters[j]){
                    max_diameter = diameters[j];
                    max_pos = j;
                }
            }
            if(max_pos != i){
                if(max_pos != diameters.size()-1){
                    cout << max_pos+1 << ' ';
                    reverse(diameters.begin() + max_pos, diameters.end());
                }
                cout << i+1 << ' ';
                reverse(diameters.begin() + i, diameters.end());
            }
        }
        cout << "0\n";
    }

    return 0;
}
