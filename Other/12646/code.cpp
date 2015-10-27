#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int a, b, c;

    while(cin >> a >> b >> c){
        if(a!=b && a!=c)        cout << "A" << endl;
        else if(b!=a && b!=c)   cout << "B" << endl;
        else if(c!=a && c!=b)   cout << "C" << endl;
        else                    cout << "*" << endl;
    }

    return 0;
}
