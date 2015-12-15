#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    unsigned long int input, output, x1, x2;
    int cases, c;

    cin >> cases;
    for(c = 1; c <= cases; c++){
        // Sol: ouptput = n*(n+1)*(n+2)/3 % 1000000007
        cin >> input;
        x1 = input + 1;
        x2 = input + 2;
        if(input %3 == 0) input /= 3;
        else if (x1 %3 == 0) x1 /= 3;
        else                 x2 /= 3;

        output = (input * x1) % 1000000007;
        output = (output * x2) % 1000000007;
        cout << "Case " << c << ": " << output << "\n";
    }
    return 0;
}
