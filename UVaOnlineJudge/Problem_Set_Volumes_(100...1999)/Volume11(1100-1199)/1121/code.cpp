#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n, s, i, j, length, sum;

    while(cin >> n >> s){
        int sequence[n];
        length = 0;
        for(i = 0; i < n; i++){
            cin >> sequence[i];
            if(length != 1){
                sum = 0;
                j = i;
                if(length == 0){
                    while(j >= 0 && sum < s){
                        sum += sequence[j];
                        j--;
                    }
                    if(sum >= s) length = i-j;
                }
                else{
                    while(j >= i-length && sum < s){
                        sum += sequence[j];
                        j--;
                    }
                    if(sum >= s && length > i-j) length = i-j;
                }
            }
        }
        cout << length << '\n';
    }

    return 0;
}
