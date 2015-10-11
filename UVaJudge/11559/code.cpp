#include <iostream>

using namespace std;

int main(){
    int participants, budget, hotels, weeks, cost, beds, price, best_price;
    int h, w;

    while(cin >> participants >> budget >> hotels >> weeks){
        best_price = budget + 1; // Best price can't be greater budget
        for(h = 0; h < hotels; h++){
            cin >> cost;

            for(w = 0; w < weeks; w++){
                cin >> beds;
                
                if(beds >= participants && (price = cost * participants) < best_price)
                    best_price = price;
            }
        }

        if(best_price <= budget)    cout << best_price << "\n";
        else                        cout << "stay home" << "\n";
    }
}
