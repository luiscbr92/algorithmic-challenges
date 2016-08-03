#include <iostream>

using namespace std;

bool is_leap(int year){
    if(year % 400 == 0)     return true;
    if(year % 100 == 0)     return false;
    if(year % 4 == 0)       return true;
    return false;
}

int main(){

    int cases, day, month, year, consumption, prev_day, prev_month, prev_year, prev_consumption, days_precise, sum_precise;
    int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while(cin >> cases && cases){
        cin >> prev_day >> prev_month >> prev_year >> prev_consumption;
        cases--;
        days_precise = 0;
        sum_precise = 0;

        while(cases--){
            cin >> day >> month >> year >> consumption;

            if(day == 1){
                if(month == 1){
                    if(prev_month == 12 && prev_day == 31 && year == prev_year+1){
                        days_precise++;
                        sum_precise += consumption - prev_consumption;
                    }
                }
                else if(month == 3){
                    if(prev_month == 2 && prev_year == year){
                        if(is_leap(year)){
                            if(prev_day == 29){
                                days_precise++;
                                sum_precise += consumption - prev_consumption;
                            }
                        }
                        else{
                            if(prev_day == 28){
                                days_precise++;
                                sum_precise += consumption - prev_consumption;
                            }
                        }
                    }
                }
                else{
                    if(month == prev_month+1 && prev_day == days_of_month[prev_month-1] && year == prev_year){
                        days_precise++;
                        sum_precise += consumption - prev_consumption;
                    }
                }

            }
            else{
                if(day == prev_day+1 && month == prev_month && year == prev_year){
                    days_precise++;
                    sum_precise += consumption - prev_consumption;
                }
            }

            prev_day = day;
            prev_month = month;
            prev_year = year;
            prev_consumption = consumption;
        }

        cout << days_precise << ' ' << sum_precise << '\n';
    }

    return 0;
}
