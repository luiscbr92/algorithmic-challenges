#include <iostream>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int i;
    string line;
    list<char> output;
    list<char>::iterator it;

    while(cin >> line){
        output.clear();
        it = output.begin();
        for(i = 0; i < line.size(); i++){
            if(line[i] == '[')      it = output.begin();
            else if(line[i] == ']') it = output.end();
            else output.insert(it, line[i]);

        }

        for(it = output.begin(); it != output.end(); it++){
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}
