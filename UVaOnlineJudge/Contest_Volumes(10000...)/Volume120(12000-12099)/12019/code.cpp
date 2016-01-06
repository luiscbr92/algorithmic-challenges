#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string days_of_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int month_lengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int cases, month, day, diff_days, month_pointer;

    cin >> cases;
    while(cases--){
        cin >> month >> day;
        month--;

        if(month < 3){
            diff_days = 4;
            month_pointer = 2;
            while(month_pointer != month){
                diff_days += month_lengths[month_pointer];
                month_pointer--;
            }
            diff_days += (month_lengths[month_pointer] - day);
            diff_days = -diff_days % 7;
            if(diff_days < 0) diff_days += 7;
        }
        else if(month == 3){
            if(day < 4){
                diff_days = (day - 4) % 7;
                if(diff_days < 0) diff_days += 7;
            }
            else if(day == 4){
                diff_days = 0;
            }
            else{
                diff_days = (day - 4) % 7;
            }
        }
        else{
            diff_days = 26;
            month_pointer = 4;
            while(month_pointer != month){
                diff_days += month_lengths[month_pointer];
                month_pointer++;
            }
            diff_days += day;
            diff_days = diff_days % 7;
        }
        
        cout << days_of_week[diff_days] << "\n";
    }

    return 0;
}
