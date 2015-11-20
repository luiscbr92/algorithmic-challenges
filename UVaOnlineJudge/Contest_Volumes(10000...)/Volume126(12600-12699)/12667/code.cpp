#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n_of_problems, n_of_teams, submissions, s, t, team_id, i, j;
    char problem;
    string veredict;

    cin >> n_of_problems >> n_of_teams >> submissions;
    int times[n_of_problems];
    int teams[n_of_problems];
    for(i = 0; i < n_of_problems; i++) times[i] = 301;
    bool problem_solved[n_of_teams][n_of_problems];
    for(i = 0; i < n_of_teams; i++){
        for(j = 0; j < n_of_problems; j++){
            problem_solved[i][j] = false;
        }
    }
    for(s = 0; s < submissions; s++){
        cin >> t >> team_id >> problem >> veredict;
        problem -= 65;

        if(problem < n_of_problems && !problem_solved[team_id][problem] && veredict == "Yes"){
            times[problem] = t;
            teams[problem] = team_id;
            problem_solved[team_id][problem] = true;
        }
    }
    for(i = 0; i < n_of_problems; i++){
        if(times[i] != 301) cout << (char)(i+65) << " " << times[i] << " " << teams[i] << endl;
        else                cout << (char)(i+65) << " - -" << endl;
    }

    return 0;
}
