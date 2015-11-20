#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    int i;

    while(getline(cin,line)){
        for(i = 0; i < line.size(); i++) line[i] -= 7;
        cout << line << endl;
    }

    return 0;
}
