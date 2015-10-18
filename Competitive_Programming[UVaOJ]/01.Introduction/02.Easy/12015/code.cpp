#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    string site[10];
    int value[10];
    int cases, max_value, i, j;

    cin >> cases;
    for(i = 1; i <= cases; i++){
        cout << "Case #" << i << ":" << endl;
        max_value = 0;

        for(j = 0; j < 10; j++){
            cin >> site[j];
            cin >> value[j];
            if(value[j] > max_value) max_value = value[j];
        }

        for(j = 0; j < 10; j++){
            if(value[j] == max_value) cout << site[j] << endl;
        }
    }

    return 0;
}
