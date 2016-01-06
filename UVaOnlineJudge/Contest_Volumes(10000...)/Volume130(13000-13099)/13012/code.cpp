#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int correct, contestant, i, count;
    while(cin >> correct){
        count = 0;
        for(i = 0; i < 5; i++){
            cin >> contestant;
            if(contestant == correct) count++;
        }

        cout << count << "\n";
    }

    return 0;
}
