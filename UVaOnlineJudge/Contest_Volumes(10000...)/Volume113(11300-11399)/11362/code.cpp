#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, list_length, i;
    string input;
    vector<string> list;
    bool consistent;
    string output = "";

    cin >> cases;
    while(cases--){
        cin >> list_length;
        list.clear();
        consistent = true;
        for(i = 0; i < list_length; i++){
            cin >> input;
            list.push_back(input);
        }
        sort(list.begin(), list.end());

        i = 0;
        while(consistent && i < list_length-1){
            if(list[i][0] == list[i+1][0] && list[i] == list[i+1].substr(0, list[i].size()))
                consistent = false;
            i++;
        }

        if(consistent)  output += "YES\n";
        else            output += "NO\n";
    }
    cout << output;

    return 0;
}
