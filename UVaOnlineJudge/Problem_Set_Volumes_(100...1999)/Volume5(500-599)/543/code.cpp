#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n){
    int square_root = sqrt(n) + 1;
    if(n <= 3) return n > 1;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i < square_root; i += 6)
        if(n%i == 0 || n%(i+2) == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio (false);

    vector<int> primes;
    int input, i, primes_length;

    for(i = 2; i < 1000001; i++)
        if(is_prime(i)) primes.push_back(i);
    primes_length = primes.size();

    while(cin >> input && input != 0){
        i = 0;
        while(i < primes_length && !is_prime(input - primes[i])) i++;

        if(i < primes_length)   cout << input << " = " << primes[i] << " + " << input-primes[i] << "\n";
        else                    cout << "Goldbach's conjecture is wrong.\n";
    }


    return 0;
}
