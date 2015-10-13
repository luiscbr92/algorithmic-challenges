#include <iostream>

using namespace std;

int main(){
    int events, supposed_treats, given_treats;
    int j, n;
    int i = 1;
    cin >> events;

    while(events > 0){
        supposed_treats = 0;
        given_treats = 0;

        for(j = 0; j < events; j++){
            cin >> n;
            if(n > 0)   supposed_treats = supposed_treats + 1;
            else        given_treats = given_treats + 1;
        }

        cout << "Case " << i << ": " << supposed_treats - given_treats << "\n";

        i++;
        cin >> events;
    }
}
