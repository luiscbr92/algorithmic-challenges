#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, i;
    stack<char> parentheses;
    string line;
    bool is_correct;

    cin >> cases;
    cin.ignore();
    while(cases--){
        getline(cin,line);
        while(!parentheses.empty()) parentheses.pop();
        is_correct = true;

        for(i = 0; i < line.size(); i++){
            if(line[i] == '[' || line[i] == '(') parentheses.push(line[i]);
            else{
                if(!parentheses.empty() && (line[i] == (char)(parentheses.top()+1) || line[i] == (char)(parentheses.top()+2)))
                    parentheses.pop();
                else{
                    is_correct = false;
                    break;
                }
            }
        }
        if(is_correct && parentheses.empty())   cout << "Yes" << endl;
        else                                    cout << "No" << endl;

    }

    return 0;
}
