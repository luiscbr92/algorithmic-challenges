#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    double a, b, c, semiperimeter, triangle_area, circumscribed_radius, circumscribed_area, inscribed_radius, inscribed_area;
    double sunflowers, violets, roses;
    double PI = 3.14159265358979323846;

    while(cin >> a >> b >> c){
        semiperimeter = (a+b+c)/2;
        triangle_area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
        circumscribed_radius = (a*b*c)/(4*triangle_area);
        inscribed_radius = triangle_area / semiperimeter;

        circumscribed_area = PI * circumscribed_radius * circumscribed_radius;
        inscribed_area = PI * inscribed_radius * inscribed_radius;

        sunflowers = circumscribed_area - triangle_area;
        violets = triangle_area - inscribed_area;
        roses = inscribed_area;

        printf("%.4f %.4f %.4f\n", sunflowers, violets, roses);
    }

    return 0;
}
