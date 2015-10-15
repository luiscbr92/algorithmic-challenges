#include <iostream>

using namespace std;

int main(){
    int cases, length, width, height;

    cin >> cases;

    for(int i = 1; i <= cases; i++){
        cin >> length >> width >> height;

        cout << "Case " << i << ": ";
        if(length <= 20 && width <= 20 && height <= 20) cout << "good\n";
        else                                            cout << "bad\n";
    }
}
