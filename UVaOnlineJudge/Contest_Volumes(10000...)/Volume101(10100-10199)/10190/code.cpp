#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    long long m, n;
    float logarithm;
    bool is_sequence;
    string result;

    while(cin >> m && cin >> n){
        if(m > 1 && n > 1 && m >= n){
            result = to_string(m);
            while(m != 1 && result != "Boring!"){
                if(m%n == 0){
                    m = m/n;
                    result += " " + to_string(m);
                }
                else result = "Boring!";
            }
        }
        else result = "Boring!";

        cout << result << "\n";

    }

    return 0;
}
