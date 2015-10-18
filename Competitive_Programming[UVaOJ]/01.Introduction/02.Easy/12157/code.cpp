#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int cases, calls, mile, juice, call_duration, i, j;

    cin >> cases;
    for(i = 1; i <= cases; i++){
        cout << "Case " << i << ": ";
        mile = 0;
        juice = 0;

        cin >> calls;
        for(j = 0; j < calls; j++){
            cin >> call_duration;
            mile = mile + (call_duration / 30 +1) * 10;
            juice = juice + (call_duration / 60 +1) * 15;
        }

        if(mile < juice)        cout << "Mile " << mile << endl;
        else if(mile > juice)   cout << "Juice " << juice << endl;
        else                    cout << "Mile Juice " << mile << endl;
    }

    return 0;
}
