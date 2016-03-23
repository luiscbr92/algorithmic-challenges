#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<int> diameters;
    string input, output;
    int space_pos, i, j, max_diameter, max_pos;

    output = "";
    while(getline(cin, input)){
        diameters.clear();
        output += input + '\n';

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
                    output += to_string(max_pos+1) + ' ';
                    reverse(diameters.begin() + max_pos, diameters.end());
                }
                output += to_string(i+1) + ' ';
                reverse(diameters.begin() + i, diameters.end());
            }
        }
        output += "0\n";
    }
    cout << output;

    return 0;
}
