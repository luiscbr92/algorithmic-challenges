#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int banks, n, debtor, creditor, value, i;
    bool liquidated_debentures;

    cin >> banks >> n;

    while(banks != 0 && n != 0){
        int money[banks];
        liquidated_debentures = true;
        for(i = 0; i < banks; i++) cin >> money[i];

        for(i = 0; i < n; i++){
            cin >> debtor >> creditor >> value;
            money[debtor-1] = money[debtor-1] - value;
            money[creditor-1] = money[creditor-1] + value;
        }

        i = 0;
        while (liquidated_debentures && i < banks) {
            if (money[i] < 0) liquidated_debentures = false;
            i = i + 1;
        }

        if(liquidated_debentures)   cout << "S\n";
        else                        cout << "N\n";

        cin >> banks >> n;
    }
    return 0;
}
