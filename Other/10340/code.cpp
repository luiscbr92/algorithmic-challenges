#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int i, length, j;
    bool subsequence;
    string a, b;

    while(cin >> a >> b){
        subsequence = true;
        i = 0;
        length = a.size();

        while(subsequence && i < length){
            if((j = b.find(a[i])) != string::npos)  b = b.substr(j+1);
            else                                    subsequence = false;
            i +=1;
        }

        if(subsequence) cout << "Yes" << endl;
        else            cout << "No" << endl;
    }

    return 0;
}
