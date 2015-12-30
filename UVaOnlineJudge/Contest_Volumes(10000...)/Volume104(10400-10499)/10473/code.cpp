#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    int integer, i;

    while(cin >> line && line[0] != '-'){
        if(line[0] == '0' && line[1] == 'x'){
            integer = 0;
            line = line.substr(2);
            reverse(line.begin(), line.end());
            for(i = 0; i < line.size(); i++){
                if(line[i] <= '9'){
                    integer += (line[i]-48) * pow(16,i);
                }
                else{
                    integer += (line[i]-65+10) * pow(16,i);
                }
            }
            printf("%d\n", integer);
        }
        else{
            integer = stoi(line);
            printf("0x%X\n", integer);
        }
    }

    return 0;
}
