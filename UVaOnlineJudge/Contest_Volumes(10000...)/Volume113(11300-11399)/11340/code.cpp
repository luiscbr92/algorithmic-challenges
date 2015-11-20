#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, n_of_characters, n_of_lines, i, j, k, n;
    char chars[100];
    int values[100];
    double cents;
    string line;

    cin >> cases;
    for(i = 0; i < cases; i++){
        cents = 0;
        cin >> n_of_characters;
        for(j = 0; j < n_of_characters; j++) cin >> chars[j] >> values[j];

        cin >> n_of_lines;
        cin.ignore();
        for(j = 0; j < n_of_lines; j++){
            getline(cin, line);
            for(n = 0; n < line.size(); n++){
                for(k = 0; k < n_of_characters; k++){
                    if(line[n] == chars[k]){
                        cents += values[k];
                        break;
                    }
                }
            }
        }

        printf("%.2f$\n", cents/100);
    }

    return 0;
}
