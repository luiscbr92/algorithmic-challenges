#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int courses_done, categories, courses_per_category, min_to_satisfy, course, courses_category;
    int  i, j, k;
    bool requirements_satisfied;

    cin >> courses_done;

    while(courses_done != 0){
        cin >> categories;
        int courses_chosen[courses_done];
        requirements_satisfied = true;

        for(i = 0; i < courses_done; i++) cin >> courses_chosen[i];

        for(i = 0; i < categories; i++){
            cin >> courses_per_category >> min_to_satisfy;
            courses_category = 0;
            for(j = 0; j < courses_per_category; j++){
                cin >> course;
                if(requirements_satisfied){
                    k = 0;
                    while(k < courses_done && courses_category < min_to_satisfy){
                        if(courses_chosen[k] == course) courses_category += 1;
                        k += 1;
                    }
                }
            }
            if(courses_category < min_to_satisfy) requirements_satisfied = false;
        }

        if(requirements_satisfied)  cout << "yes" << endl;
        else                        cout << "no" << endl;

        cin >> courses_done;
    }

    return 0;
}
