#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int nums, i, prev, curr;
    list<int> difference;

    while(cin >> nums){
        difference.clear();
        if(nums == 1){
            cin >> curr;
            cout << "Jolly\n";
            continue;
        }

        for(i = 1; i < nums; i++) difference.push_back(i);

        for(i = 0; i < nums; i++){
            if(i > 0) prev = curr;
            cin >> curr;
            if(i > 0) difference.remove(abs(prev-curr));
        }

        if(difference.empty())  cout << "Jolly\n";
        else                    cout << "Not jolly\n";

    }

    return 0;
}
