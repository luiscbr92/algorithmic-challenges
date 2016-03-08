#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string input, output;
    int cases, hour, minute;

    cin >> cases;
    while(cases--){
        cin >> input;
        hour = 10* (input[0] - '0') + (input[1] - '0');
        minute = 10* (input[3] - '0') + (input[4] - '0');
        output = "";

        if(minute == 0){
            if(hour != 12)  hour = 12 - hour;
        }
        else{
            minute = 60 - minute;
            hour = 12 - hour -1;
            if(hour == 0)       hour = 12;
            else if(hour == -1) hour = 11;
        }

        output += char(hour/10 + '0');
        output += char(hour%10 + '0');
        output += ':';
        output += char(minute/10 + '0');
        output += char(minute%10 + '0');
        output += '\n';
        cout << output;
    }

    return 0;
}
