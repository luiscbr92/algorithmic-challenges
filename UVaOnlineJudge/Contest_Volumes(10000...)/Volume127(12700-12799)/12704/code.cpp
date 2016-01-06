#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    double x, y, r, shortest, longest, distance;
    int cases;

    cin >> cases;
    while(cases--){
        cin >> x >> y >> r;
        distance = sqrt(x*x + y*y);
        shortest = r - distance;
        longest = r + distance;

        printf("%.2f %.2f\n", shortest, longest);
    }

    return 0;
}
