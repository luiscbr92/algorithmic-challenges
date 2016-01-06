#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, i;
    string a, b;
    bool same;

    cin >> cases;
    while(cases--){
        same = true;
        cin >> a >> b;
        if(a.size() == b.size()){
            for(i = 0; i < a.size(); i++){
                if(a[i] != b[i]){
                    if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u') same = false;
                    if(b[i] != 'a' && b[i] != 'e' && b[i] != 'i' && b[i] != 'o' && b[i] != 'u') same = false;
                }
            }
        }
        else same = false;

        if(same) cout << "Yes\n";
        else     cout << "No\n";
    }

    return 0;
}
