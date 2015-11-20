#include <iostream>

using namespace std;

int *srtins(int foo[]){
    int tmp, i, j;

    for(i = 1; i < 3; i++){
        j = i-1;

        tmp = foo[i];
        while(j>=0 && foo[j]>tmp){
            foo[j+1] = foo[j];
            j = j-1;
        }
        foo[j+1] = tmp;
    }

    return foo;
}

int main(){
    int testcases, a, b, c;
    int foo[3];

    cin >> testcases;

    for(int i = 1; i <= testcases; i++){
        cin >> a >> b >> c;

        foo[0] = a;
        foo[1] = b;
        foo[2] = c;
        srtins(foo);

        cout << "Case " << i << ": " << foo[1] << "\n";
    }


}
