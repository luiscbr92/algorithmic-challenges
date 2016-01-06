#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    char code[] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};
    int cases, i, j;
    string line;
    vector<string> message;
    bool is_first = true;

    cin >> cases;
    cin.ignore();
    while(cases--){
        message.clear();
        getline(cin, line);
        while(line != ""){
            message.push_back(line);
            getline(cin, line);
        }

        for(i = 0; i < message.size(); i++){
            for(j = 0; j < message[i].size(); j++){
                if(message[i][j] >= '0' && message[i][j] <= '9')
                    message[i][j] = code[message[i][j]-48];
                }
        }

        if(is_first) is_first = false;
        else         cout << "\n";

        for(i = 0; i < message.size(); i++) cout << message[i] << "\n";
    }
    return 0;
}
