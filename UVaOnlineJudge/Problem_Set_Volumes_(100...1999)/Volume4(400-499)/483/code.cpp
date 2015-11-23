#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    stack<char> my_stack;
    string line, result;
    int i;
    bool is_first;

    while(getline(cin,line)){
        result = "";
        is_first = true;

        for(i = 0; i < line.size(); i++){
            if(line[i] == ' '){
                if(!is_first)   result += " ";
                else            is_first = false;
                while(!my_stack.empty()){
                    result += my_stack.top();
                    my_stack.pop();
                }
            }
            else my_stack.push(line[i]);
        }

        if(!is_first) result += " ";
        while(!my_stack.empty()){
            result += my_stack.top();
            my_stack.pop();
        }


        cout << result << endl;
    }

    return 0;
}
