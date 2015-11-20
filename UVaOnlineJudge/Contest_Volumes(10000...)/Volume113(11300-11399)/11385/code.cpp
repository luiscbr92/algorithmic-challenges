#include <iostream>
#include <math.h>

using namespace std;

// This function returns the i-esime value of fibonacci with n0=1 and n1=2
// The function has been calculated by using linear homogeneous recurrence relations
int fibonacci(int i){
    // IMPORTANT: write 0.5 instead of 1/2
    return (((0.5) + (3/(2*sqrt(5)))) * pow((1+sqrt(5))/2, i)) + (((0.5) - (3/(2*sqrt(5)))) * pow((1-sqrt(5))/2, i));
}

int main(){
    ios_base::sync_with_stdio (false);

    int cases, n_of_caps, n_of_spaces, tmp, i, j, k;
    char caps_tmp;
    char caps[100];
    int fib[100];
    string line, result;

    cin >> cases;
    for(i = 0; i < cases; i++){
        cin >> n_of_caps;

        for(j = 0; j < n_of_caps; j++){
            cin >> fib[j];
        }
        cin.ignore();

        getline(cin, line);
        j = 0;
        while(line.size() > 0){
            if((char)line[0] >= 65 && (char)line[0] <= 90){
                caps[j] = line[0];
                j += 1;
            }
            line = line.substr(1);
        }

        // Using insertion sort with fib with caps
        for(j = 1; j < n_of_caps; j++){
            k = j - 1;
            tmp = fib[j];
            caps_tmp = caps[j];
            while(k >= 0 and fib[k] > tmp){
                fib[k+1] = fib[k];
                caps[k+1] = caps[k];
                k -= 1;
            }
            fib[k+1] = tmp;
            caps[k+1] = caps_tmp;
        }

        // Preparing the deciphered text
        result = "";
        n_of_spaces = 0;
        j = 0;
        while(j < n_of_caps){
            // If the next character is correct, add it to result. Else add a space.
            if(fibonacci(j + n_of_spaces) == fib[j]){
                result += caps[j];
                j += 1;
            }
            else{
                result += ' ';
                n_of_spaces += 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
