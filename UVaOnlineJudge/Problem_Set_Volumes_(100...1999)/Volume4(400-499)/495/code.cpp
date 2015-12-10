#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sum(string a, string b){
    string result = "";
    int carry_over = 0;
    int index_a = a.size() -1;
    int index_b = b.size() -1;
    int a_digit, b_digit, amount;

    while(index_a > -1 || index_b > -1 || carry_over != 0){
        a_digit = 0;
        if(index_a > -1) a_digit += int(a[index_a]) - 48;
        b_digit = 0;
        if(index_b > -1) b_digit += int(b[index_b]) - 48;

        amount = a_digit + b_digit + carry_over;

        if(amount > 9){
            carry_over = 1;
            amount -= 10;
        }
        else carry_over = 0;

        result = char(amount+48) + result;
        index_a--;
        index_b--;
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio (false);

    int input;
    vector<string> fibonacci;
    fibonacci.push_back("0");
    fibonacci.push_back("1");
    int fibonacci_length = 2;

    while(fibonacci_length < 5001){
        fibonacci.push_back(sum(fibonacci.at(fibonacci_length-1), fibonacci.at(fibonacci_length-2)));
        fibonacci_length++;
    }

    while(cin >> input){

        cout << "The Fibonacci number for " << input << " is " << fibonacci.at(input) << "\n";
    }

    return 0;
}
