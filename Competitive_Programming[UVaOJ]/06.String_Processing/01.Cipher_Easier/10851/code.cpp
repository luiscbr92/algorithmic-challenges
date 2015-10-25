#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, length, i, j, k;
    int ascii[80];
    string line, result;

    cin >> cases;
    cin.ignore();

    for(i = 0; i < cases; i++){
        result = "";
        getline(cin, line);
        length = line.size() - 2;
        for(j = 0; j < length; j++) ascii[j] = 0;

        for(j = 0; j < 7; j++){
            getline(cin, line);
            for(k = 0; k < length; k++){
                if(line[k+1] == '\\'){
                    ascii[k] += pow(2,j);
                }
            }
        }

        for(j = 0; j < length; j++){
            result += (char)ascii[j];
        }
        cout << result << endl;

        if(i < cases -1){
            getline(cin, line); // Read the penultimate line
            getline(cin, line); // Read the last line
            getline(cin, line); // Read the empty line between two cases
        }
    }
    return 0;
}
