#include <iostream>

using namespace std;

int main(){
    int cases, stores, smallest, greatest, i, j, position;

    cin >> cases;

    for(i = 0; i < cases; i++){
        cin >> stores;

        // Read first store position
        cin >> position;
        smallest = position;
        greatest = position;

        // Read the rest of positions
        for(j = 1; j < stores; j++){
            cin >> position;
            if(position < smallest) smallest = position;
            if(position > greatest) greatest = position;
        }

        cout << (greatest-smallest)*2 << "\n";
    }

}
