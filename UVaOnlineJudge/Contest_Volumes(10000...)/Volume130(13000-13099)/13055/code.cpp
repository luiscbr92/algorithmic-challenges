#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    stack<string> people;
    string line;
    int cases;

    cin >> cases;
    cin.ignore();
    while(cases--){
        getline(cin, line);
        //cout << line << endl;

        if(line == "Test"){
            if(people.empty())  cout << "Not in a dream\n";
            else                cout << people.top() << "\n";
        }
        else if(line == "Kick"){
            if(!people.empty()) people.pop();
        }
        else{
            line = line.substr(6);
            people.push(line);
        }
    }

    return 0;
}
