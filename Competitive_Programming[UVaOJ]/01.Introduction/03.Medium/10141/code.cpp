#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int requirements, proposals, requirements_met, money, i, j;
    float price, best_price, compliance, best_compliance;
    int rfp = 1;
    string best_proposal, organization, ignoring;

    cin >> requirements >> proposals;

    while(requirements != 0 && proposals != 0){
        cin.ignore();
        for(i = 0; i < requirements; i++) getline(cin, ignoring);

        // Read first proposal in order to initialize best_price, best_compliance and best_proposal
        getline(cin, organization);
        best_proposal = organization;
        cin >> price >> requirements_met;
        cin.ignore();
        best_price = price;
        best_compliance = (float)requirements_met / (float)requirements;

        for(j = 0; j < requirements_met; j++) getline(cin, ignoring);

        // Read successive proposals
        for(i = 1; i < proposals; i++){
            getline(cin, organization);
            cin >> price >> requirements_met;
            cin.ignore();

            if((compliance = (float)requirements_met / (float)requirements) > best_compliance){
                best_proposal = organization;
                best_price = price;
                best_compliance = compliance;
            }
            else if(compliance == best_compliance){
                if(price < best_price){
                    best_proposal = organization;
                    best_price = price;
                    best_compliance = compliance;
                }
            }
            for(j = 0; j < requirements_met; j++) getline(cin, ignoring);
        }

        if(rfp > 1) cout << endl;
        cout << "RFP #" << rfp << endl;
        cout << best_proposal << endl;

        cin >> requirements >> proposals;
        rfp += 1;
    }

    return 0;
}
