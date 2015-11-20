#include <iostream>
#include <string>

using namespace std;

int value(string s){
    int s_value = 0;
    int i, ascii, aux, sum;

    for(i = 0; i < s.size(); i++){
        ascii = int(s[i]);
        if(ascii >=  65 && ascii <= 90) s_value += (ascii - 64);
        else if(ascii >= 97 && ascii <=122) s_value += (ascii - 96);
    }

    while(s_value >= 10){
        aux = s_value;
        sum = 0;
        while(aux >= 10){
            sum += aux % 10;
            aux /= 10;
        }
        sum += aux;
        s_value = sum;
    }
    return s_value;
}


int main(){
    ios_base::sync_with_stdio (false);

    string a, b;
    int a_value, b_value, i, ascii;
    float ratio;

    while(getline(cin, a) && getline(cin, b)){
        a_value = value(a);
        b_value = value(b);

        if(a_value != 0 || b_value != 0){
            if(a_value > b_value)   ratio = (float)b_value / (float)a_value * 100;
            else                    ratio = (float)a_value / (float)b_value * 100;

            printf("%.2f %%\n", ratio);
        }
        else printf("\n");
    }

    return 0;
}
