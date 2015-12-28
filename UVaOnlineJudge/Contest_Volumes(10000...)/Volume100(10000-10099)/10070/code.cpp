#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    bool is_leap, is_huluculu, is_bulukulu;
    bool divisible_3, divisible_4, divisible_5, divisible_11, divisible_100, divisible_400;
    string year;
    int pairs, odds, test_3, i, length, units, tens, hundreds, thousand_units;
    bool is_first = true;

    while(cin >> year){
        is_leap = false;
        is_huluculu = false;
        is_bulukulu = false;

        length = year.size();
        units = year[length-1] -48;
        tens = year[length-2] -48;
        hundreds = year[length-3] -48;
        thousand_units = year[length-4] -48;

        divisible_4 = (units + 10 * tens) % 4 == 0;
        divisible_5 = units % 5 == 0;
        divisible_100 = units == 0 && tens == 0;
        divisible_400 = ((hundreds + 10 * thousand_units) % 4 == 0) && units == 0 && tens == 0;

        test_3 = 0;
        pairs = 0;
        odds = 0;
        for(i = 0; i < length; i++){
            test_3 += year[i] -48;
            if(i % 2 == 0) pairs += year[i] -48;
            else           odds += year[i] -48;
        }
        divisible_3 = test_3 % 3 == 0;
        divisible_11 = (pairs - odds) % 11 == 0;

        if(divisible_400 || divisible_4 && !divisible_100){
            is_leap = true;
            if(divisible_11 && divisible_5) is_bulukulu = true;
        }
        if(divisible_3 && divisible_5) is_huluculu = true;

        if(!is_first)   cout << "\n";
        else            is_first  = false;

        if(is_leap)     cout << "This is leap year.\n";
        if(is_huluculu) cout << "This is huluculu festival year.\n";
        if(is_bulukulu) cout << "This is bulukulu festival year.\n";
        if(!is_leap && !is_huluculu && !is_bulukulu) cout << "This is an ordinary year.\n";
    }

    return 0;
}
