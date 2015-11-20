#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int tam, i, temp;
    queue<int> objetive;
    stack<int> med;
    queue<int> buffer;

    while(cin >> tam && tam != 0){
        while(cin >> temp && temp !=0){
            while(!objetive.empty()) objetive.pop();
            while(!buffer.empty()) buffer.pop();
            while(!med.empty()) med.pop();

            for(i = 1; i <= tam; i++) buffer.push(i);

            objetive.push(temp);
            for(i = 1; i < tam; i++){
                cin >> temp;
                objetive.push(temp);
            }

            while(!objetive.empty() && (!buffer.empty() || !med.empty() && med.top() == objetive.front())){
                if(!med.empty() && med.top() == objetive.front()){
                    med.pop();
                    objetive.pop();
                }
                else{
                    med.push(buffer.front());
                    buffer.pop();
                }
            }

            if(objetive.empty())    cout << "Yes" << endl;
            else                    cout << "No" << endl;
        }
        cout << endl;
    }

    return 0;
}
