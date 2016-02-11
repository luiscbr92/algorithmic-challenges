#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<double> expenses;
    double  result1, result2, average, tmp;
    int number_of_students, i;

    while(cin >> number_of_students && number_of_students != 0){
        expenses.clear();
        average = 0;
        result1 = 0;
        result2 = 0;

        for(i = 0; i < number_of_students; i++){
            cin >> tmp;
            expenses.push_back(tmp);
            average += tmp;
        }
        average /= number_of_students;

        for(i = 0; i < number_of_students; i++){
            if(expenses[i] < average){
                result1 += long((average - expenses[i])*100)/100.0;
            }
            else if(expenses[i] > average){
                result2 += long((expenses[i] - average)*100)/100.0;
            }
        }

        if(result1 > result2) printf("$%.2f\n", result1);
        else                  printf("$%.2f\n", result2);
    }

    return 0;
}
