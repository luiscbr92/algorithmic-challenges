#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int length, width, height, theta;
    double areaA, areaB, projA, projB, volume, rad;
    double pi = 3.1415926535897;

    while(cin >> length >> width >> height >> theta){
        if(theta > 0){
            rad = theta * pi / 180.0;

            projA = height / tan(rad);
            projB = length * tan(rad);

            areaA = (projA * height) /2;
            areaB = (projB * length) /2;

            if(areaA > areaB)   volume = (length * width * height) - (areaB * width);
            else                volume = areaA * width;

        } else volume = length * width * height;

        printf("%.3f mL\n", volume);
    }

    return 0;
}
