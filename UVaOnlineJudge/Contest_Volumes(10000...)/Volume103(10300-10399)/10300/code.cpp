#include <iostream>

using namespace std;
/***********************************************************************
*            space_per_animal = size_farmyard / #_animals              *
*                                                                      *
*  premium = space_per_animal * parameter_env_friendliness * animals   *
*                                                                      *
*                                                                      *
* If we replace the first equation in the second one, we obtain:       *
*                                                                      *
*         premium = size_farmyard * parameter_env_friendliness         *
***********************************************************************/

int main(){
    long cases, farmers, i, j, environment_friendliness, animals, size_farmyard, amount;
    cin >> cases;

    for(i = 0; i < cases; i++){
        cin >> farmers;
        amount = 0;

        for(j = 0; j < farmers; j++){
            cin >> size_farmyard >> animals >> environment_friendliness;
            amount = amount + size_farmyard * environment_friendliness;
        }

        cout << amount << "\n";
    }

}
