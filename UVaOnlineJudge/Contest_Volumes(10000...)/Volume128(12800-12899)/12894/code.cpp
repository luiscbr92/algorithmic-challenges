#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases;
    double x0, y0, x1, y1, xc, yc, r, length, width, to_centre_x, to_centre_y;
    bool is_pefect_flag;

    cin >> cases;
    while(cases--){
        cin >> x0 >> y0 >> x1 >> y1 >> xc >> yc >> r;
        is_pefect_flag = true;
        length = x1 - x0;
        width = y1 - y0;
        to_centre_x = xc - x0;
        to_centre_y = yc - y0;

        if(width*10/6.0 != length) is_pefect_flag = false;
        if(is_pefect_flag && r*5 != length) is_pefect_flag = false;
        if(is_pefect_flag && to_centre_x * 20 / 9.0 != length) is_pefect_flag = false;
        if(is_pefect_flag && to_centre_y * 2 != width) is_pefect_flag = false;

        if(is_pefect_flag)  cout << "YES\n";
        else                cout << "NO\n";
    }

    return 0;
}
