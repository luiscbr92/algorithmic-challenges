#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int initial, tarjet, current_number, current_tap, tmp;
    queue<int> next_to_check;
    queue<int> taps;
    bool found;

    while(cin >> initial >> tarjet){
        vector<bool> visited (10000, false);
        visited[initial] = true;
        while(!next_to_check.empty())   next_to_check.pop();
        while(!taps.empty())            taps.pop();
        found = false;

        next_to_check.push(initial);
        taps.push(0);
        current_tap = 0;

        while(!found && next_to_check.front() != tarjet){
            current_number = next_to_check.front();
            current_tap = taps.front() + 1;
            next_to_check.pop();
            taps.pop();

            tmp = (current_number + 1) % 10000;
            if(tmp == tarjet) found = true;
            else{
                if(!visited[tmp]){
                    next_to_check.push(tmp);
                    taps.push(current_tap);
                    visited[tmp] = true;
                }
            }

            tmp = (current_number * 2) % 10000;
            if(tmp == tarjet) found = true;
            else{
                if(!visited[tmp]){
                    next_to_check.push(tmp);
                    taps.push(current_tap);
                    visited[tmp] = true;
                }
            }

            tmp = (current_number / 3) % 10000;
            if(tmp == tarjet) found = true;
            else{
                if(!visited[tmp]){
                    next_to_check.push(tmp);
                    taps.push(current_tap);
                    visited[tmp] = true;
                }
            }
        }

        cout << current_tap << '\n';

    }

    return 0;
}
