#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int number, sum, i;
    string output = "PERFECTION OUTPUT\n";

    while(cin >> number && number){
        if(number == 1){
            output += "    1  DEFICIENT\n";
            continue;
        }
        if(number < 10)         output += "    ";
        else if(number < 100)   output += "   ";
        else if(number < 1000)  output += "  ";
        else if(number < 10000) output += " ";
        output += to_string(number) + "  ";

        sum = 1;
        for(i = 2; i < number/2+1; i++)
            if(number % i == 0) sum += i;

        if(sum == number)       output += "PERFECT\n";
        else if(sum < number)   output += "DEFICIENT\n";
        else                    output += "ABUNDANT\n";
    }
    output += "END OF OUTPUT\n";
    cout << output;

    return 0;
}
