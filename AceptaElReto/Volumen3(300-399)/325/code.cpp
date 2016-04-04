#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    bool is_first;
    int cases, number_of_chocolate, number_of_vainilla, i;
    string ice_cream, result;

    cin >> cases;
    while(cases--){
        cin >> number_of_chocolate >> number_of_vainilla;
        is_first = true;
        result = "";

        ice_cream = "";
        for(i = 0; i < number_of_chocolate; i++) ice_cream += "C";
        for(i = 0; i < number_of_vainilla;  i++) ice_cream += "V";

        do{
            if(is_first)    is_first = false;
            else            result += ' ';
            result += ice_cream;
        }while(next_permutation(ice_cream.begin(), ice_cream.end()));

        cout << result << '\n';
    }
    return 0;
}
