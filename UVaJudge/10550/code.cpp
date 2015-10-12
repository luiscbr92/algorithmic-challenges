#include <iostream>

using namespace std;

int main(){
    int ini, a, b, c, degrees;

    cin >> ini >> a >> b >> c;

    while(ini != 0 || a != 0 || b != 0 || c != 0){

        degrees = 1080; // During the process I will do 3 complete turns: 360*3 = 1080

        /* 360/40 = 9 degrees for each dial division unit*/
        // From ini to a
        if(ini >= a)    degrees = degrees + 9 * (ini - a);
        else            degrees = degrees + 9 * ini + 9 * (40 - a);

        // From a to b
        if(a <= b)      degrees = degrees + 9 * (b - a);
        else            degrees = degrees + 9 * (40 - a) + 9 * b;

        // From b to c
        if(b >= c)      degrees = degrees + 9 * (b - c);
        else            degrees = degrees + 9 * b + 9 * (40 - c);

        cout << degrees << "\n";

        cin >> ini >> a >> b >> c;
    }
}
