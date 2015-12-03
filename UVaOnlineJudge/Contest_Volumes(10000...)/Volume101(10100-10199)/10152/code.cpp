#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, turtles, t, index_origin, index_final;
    string line;
    vector<string> original;
    vector<string> final;
    string result;

    cin >> cases;

    for(c = 0; c < cases; c++){
        original.clear();
        final.clear();
        cin >> turtles;
        cin.ignore();
        for(t = 0; t < turtles; t++){
            getline(cin, line);
            original.push_back(line);
        }
        for(t = 0; t < turtles; t++){
            getline(cin, line);
            final.push_back(line);
        }

        index_origin = t-1;
        index_final = t-1;

        while(index_origin != -1){
            if(original[index_origin] == final[index_final]) index_final--;
            index_origin--;
        }

        while(index_final != -1){
            result += final[index_final] + "\n";
            index_final--;
        }

        result += "\n";
    }
    cout << result;

    return 0;
}
