#include <iostream>

using namespace std;

int main(){
    int i;
    bool inQuotes = false;
    string line, letter;

    while(getline(cin, line)){
        for(i = 0; i < line.length(); i++){
            letter = line[i];
            if(letter == "\""){
                if(inQuotes)    cout << "\'\'";
                else            cout << "``";
                inQuotes = !inQuotes;
            }
            else cout << letter;
        }
        cout << "\n";
    }
}
