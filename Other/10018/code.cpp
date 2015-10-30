#include <iostream>
#include <cmath>

using namespace std;

long long revert(long long num){
    long long reverse = 0;
    while(num >= 10){
        reverse += num%10;
        reverse *= 10;
        num /= 10;
    }
    reverse += num;

    return reverse;
}

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, iterations;
    long long num, reverse;

    cin >> cases;
    for(c = 0; c < cases; c++){
        cin >> num;
        iterations = 1;
        num += revert(num);

        while((reverse=revert(num)) != num){
            num += reverse;
            iterations +=1;
        }

        cout << iterations << " " << num << endl;
    }

    return 0;
}
