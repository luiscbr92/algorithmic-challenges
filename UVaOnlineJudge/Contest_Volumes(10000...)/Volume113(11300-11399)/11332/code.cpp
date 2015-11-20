#include <iostream>

using namespace std;

int f(int n){
    int sum = 0;
    if(n >= 10){
        while(n >= 10){
            sum = sum + n%10;
            n = n / 10;
        }
        sum = sum + n;

        return f(sum);
    }
    else return n;
}

int main(){
    int n;

    cin >> n;

    while(n > 0){
        cout << f(n) << endl;

        cin >> n;
    }

}
