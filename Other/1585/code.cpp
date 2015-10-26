#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, result, consecutive, i, j;
    string line;

    cin >> cases;
    cin.ignore();

    for(i = 0; i < cases; i++){
        result = 0;
        consecutive = 0;

        getline(cin,line);

        for(j = 0; j < line.size(); j++){
            if(line[j] == 'O'){
                consecutive += 1;
                result += consecutive;
            }
            else consecutive = 0;
        }

        cout << result << endl;
    }

    return 0;
}
