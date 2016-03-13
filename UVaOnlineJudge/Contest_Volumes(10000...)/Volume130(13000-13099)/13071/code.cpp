#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, above, below;
    string output = "";

    cin >> cases;
    while(cases--){
        cin >> above >> below;
        output += to_string((above+below+1)*(above+below+2)/2 - below) + '\n';
    }

    cout << output;

    return 0;
}
