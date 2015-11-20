#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int a, b, sum, cases, c;

    cin >> cases;
    for(c = 1; c <= cases; c++){
        cin >> a >> b;
        sum = 0;
        if(a % 2 == 0) a++;
        for(a; a <= b; a += 2) sum += a;
        cout << "Case " << c << ": " << sum << endl;
    }

    return 0;
}
