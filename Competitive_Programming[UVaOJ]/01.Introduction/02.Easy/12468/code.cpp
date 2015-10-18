#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int a, b, distance;

    cin >> a >> b;
    while(a != -1 && b != -1){
        if(a > b)   distance = a - b;
        else        distance = b - a;

        if(distance > 50) distance = 50 -(distance - 50);

        cout << distance << endl;
        cin >> a >> b;
    }
    return 0;
}
