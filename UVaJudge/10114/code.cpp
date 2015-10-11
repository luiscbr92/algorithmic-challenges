#include <iostream>

using namespace std;

int main(){
    double car_value; // Current car value
    int month; // Current month
    int total_months;

    int next_case, cases; // Used to control reading depreciations
    int month_depreciation; // First month with the current depreciation value
    double current_depreciation;
    int next_month_depreciation; // Next month with different depreciation
    double next_depreciation; 

    double owing, down_payment, loan, payment;

    cin >> total_months >> down_payment >> loan >> cases;

    while(total_months > 0){
        car_value = loan + down_payment;
        owing = loan;
        payment = loan / total_months;

        // I read first case and next one
        cin >> month_depreciation >> current_depreciation;

        next_case = 2;
        if(next_case <= cases){
            cin >> next_month_depreciation >> next_depreciation;
            next_case = next_case + 1;
        }
        else next_month_depreciation = 101; // total_months can't be greater than 100

        // Month 0
        month = 0;
        owing = loan;
        car_value = car_value * (1 - current_depreciation);

        // Successive months
        while (owing > car_value){
            month = month + 1;
            if(month == next_month_depreciation){
                month_depreciation = next_month_depreciation;
                current_depreciation = next_depreciation;

                if(next_case <= cases){
                    cin >> next_month_depreciation >> next_depreciation;
                    next_case = next_case + 1;
                }
                else next_month_depreciation = 101; // total_months can't be greater than 100
            }

            owing = owing - payment;
            car_value = car_value * (1 - current_depreciation);

        }

        // I've already discover the months, but if I didn't read all cases, I do it now
        while(next_case <= cases){
            cin >> next_month_depreciation >> next_depreciation;
            next_case = next_case + 1;
        }


        if (month != 1) cout << month << " months\n";
        else            cout << "1 month\n";

        // Read the next loan
        cin >> total_months >> down_payment >> loan >> cases;
    }
}
