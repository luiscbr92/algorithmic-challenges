#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int period, popes, i, j, year, first_year, last_year, max_popes, new_popes;
    int years[100000];

    while(cin >> period){
        cin >> popes;
        max_popes = 1;

        for(i = 0; i < popes; i++) cin >> years[i];
        // Note that j-i+1 is the number of popes elected from years[i] to years[j]
        for(i = 0; i + max_popes < popes; i++){
            j = i + max_popes;
            while(j < popes && years[j]-years[i] <= period-1) j += 1;
            j -= 1;

            if((new_popes = j-i+1) > max_popes){
                max_popes = new_popes;
                first_year = years[i];
                last_year = years[j];
            }
        }

        cout << max_popes << " " << first_year << " " << last_year << endl;
    }
    return 0;
}
