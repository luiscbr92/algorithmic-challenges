#include <iostream>
#include <string>

using namespace std;

int main(){
    int cases, donation;
    string line;
    int amount = 0;

    cin >> cases;

    for (int i = 0; i < cases; i++){
        cin >> line;

        if(line == "report") cout << amount << "\n";

        else{
            cin >> donation;
            amount = amount + donation;
        }
    }
}
