#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int cases, height, width, m, n;

    cin >> cases;

    for(int i = 0; i < cases; i++){
        cin >> height >> width;

        m = ceil((height-2)/3.0);
        n = ceil((width-2)/3.0);

        cout << m*n <<"\n";
    }
}
