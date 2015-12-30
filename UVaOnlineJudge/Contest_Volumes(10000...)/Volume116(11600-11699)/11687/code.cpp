#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    int i, x;

    while(cin >> line && line != "END"){
        if(line != "1"){
            i = 1;
            x = line.size();
            while(x != 1){
                i++;
                if(x < 10)              x = 1;
                else if (x < 100)       x = 2;
                else if (x < 1000)      x = 3;
                else if (x < 10000)     x = 4;
                else if (x < 100000)    x = 5;
                else if (x < 1000000)   x = 6;
                else                    x = 7;
            }
            cout << i + 1 << "\n";
        }
        else cout << 1 << "\n";
    }

    return 0;
}
