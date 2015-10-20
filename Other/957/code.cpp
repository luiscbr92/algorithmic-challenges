#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int period, popes, i, j, year, first_year, last_year, max_popes;

    while(cin >> period){
        cin >> popes;
        int years[popes];
        max_popes = 0;

        for(i = 0; i < popes; i++) cin >> years[i];
        // Note that j-i+1 is the number of popes elected from years[i] to years[j]
        for(i = 0; i < popes; i++){
            j = i + 1;
            while(j < popes && years[j]-years[i] <= period-1) j += 1;
            j -= 1;

            if(j-i+1 > max_popes){
                max_popes = j-i+1;
                first_year = years[i];
                last_year = years[j];
            }
        }

        cout << max_popes << " " << first_year << " " << last_year << endl;
    }
    return 0;
}
