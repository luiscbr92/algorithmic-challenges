#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<string> months_haab = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    vector<string> days_tzolkin = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    int cases;
    int haab_day_of_month, haab_month, haab_year;
    int tzolkin_day_number, tzolkin_day_name, tzolkin_year;
    int separator_a, separator_b;
    int total_days;
    string haab_date, tzolkin_date;
    string haab_month_str;

    cin >> cases;
    cout << cases << "\n";
    cin.ignore();
    while(cases--){
        getline(cin, haab_date);
        separator_a = haab_date.find(". ");
        separator_b = haab_date.rfind(" ");

        haab_day_of_month = stoi(haab_date.substr(0,separator_a));
        separator_a +=2;
        haab_month_str = haab_date.substr(separator_a, separator_b-separator_a);
        haab_year = stoi(haab_date.substr(separator_b+1));
        // cout << haab_day_of_month << " " << haab_month_str << " " << haab_year << endl;

        haab_month = 0;
        while(haab_month < 19 && months_haab[haab_month] != haab_month_str) haab_month++;
        total_days = haab_year * 365 + haab_month * 20 + haab_day_of_month;

        tzolkin_year = total_days / 260;
        tzolkin_day_number = total_days %13 +1;
        tzolkin_day_name = total_days %20;

        cout << tzolkin_day_number << " " << days_tzolkin[tzolkin_day_name] << " " << tzolkin_year << "\n";








    }

    return 0;
}
