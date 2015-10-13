#include <iostream>

using namespace std;

int main(){
    string line;
    int i = 1;

    while(getline(cin, line) && line[0] != '#'){
        if(line=="HELLO")               cout << "Case " << i << ": ENGLISH\n";
        else if(line=="HOLA")           cout << "Case " << i << ": SPANISH\n";
        else if(line=="HALLO")          cout << "Case " << i << ": GERMAN\n";
        else if(line=="BONJOUR")        cout << "Case " << i << ": FRENCH\n";
        else if(line=="CIAO")           cout << "Case " << i << ": ITALIAN\n";
        else if(line=="ZDRAVSTVUJTE")   cout << "Case " << i << ": RUSSIAN\n";
        else                            cout << "Case " << i << ": UNKNOWN\n";

        i++;
    }
}
