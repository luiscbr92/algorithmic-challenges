#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sum(string a, string b){
    string output = "";
    int a_digit, b_digit, semi_sum;
    int carry_out = 0;
    int a_index = a.size() -1;
    int b_index = b.size() -1;

    while(a_index >= 0 || b_index >= 0 || carry_out){
        if(a_index >= 0)    a_digit = a[a_index] - '0';
        else                a_digit = 0;

        if(b_index >= 0)    b_digit = b[b_index] - '0';
        else                b_digit = 0;

        semi_sum = a_digit + b_digit + carry_out;
        output = char('0' + semi_sum % 10) + output;
        carry_out = semi_sum /10;

        a_index--;
        b_index--;
    }

    return output;
}

int main(){
    ios_base::sync_with_stdio (false);

    vector<string> fib;
    fib.push_back("0");
    fib.push_back("1");
    int fib_index;
    string output = "";

    while(cin >> fib_index){
        while(fib_index >= fib.size())
            fib.push_back(sum(fib[fib.size()-1], fib[fib.size()-2]));
        output += fib[fib_index] + '\n';
    }
    cout << output;

    return 0;
}
