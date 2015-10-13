#include <iostream>

using namespace std;

int main(){
    string line;
    int i = 1;

    cin >> line;

    while(line!="*"){
        cout << "Case " << i << ": Hajj-e-";

        if(line=="Hajj")    cout << "Akbar\n";
        else                cout << "Asghar\n";

        i = i+1;
        cin >> line;
    }
}
