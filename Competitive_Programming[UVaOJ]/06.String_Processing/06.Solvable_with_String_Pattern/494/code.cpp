#include <iostream>

using namespace std;

bool isLetter(char c){
    return ((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122);
}

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    int words, i;
    bool inWord;

    while(getline(cin, line)){
        inWord = false;
        words = 0;

        for(i = 0; i < line.size(); i++){
            if(!inWord && isLetter(line[i])){
                words += 1;
                inWord = true;
            }
            else if(inWord && !isLetter(line[i])) inWord = false;
        }
        cout << words << endl;
    }

    return 0;
}
