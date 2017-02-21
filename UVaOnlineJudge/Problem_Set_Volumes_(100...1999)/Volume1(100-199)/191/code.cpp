#include <iostream>

#define endl '\n'

using namespace std;

struct Point{
  int x, y;
};

bool inter(Point a, Point b, Point c, Point d) {
    double s, t, num, denom;
    denom = a.x*double(d.y-c.y)+b.x*double(c.y-d.y)+
            d.x*double(b.y-a.y)+c.x*double(a.y-b.y);
    if (denom == 0.0) return false;

    num = a.x*double(d.y-c.y)+c.x*double(a.y-d.y)+d.x*double(c.y-a.y);
    s = num/denom;

    num = -(a.x*double(c.y-b.y)+b.x*double(a.y-c.y)+c.x*double(b.y-a.y));
    t = num/denom;

    return (0.0 <= s && s <= 1.0 && 0.0 <= t && t <= 1.0);
}

void printPoint(Point p) {
    cout << p.x << " " << p.y << endl;
}

int main() {
  int cases, xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
  cin >> cases;


  while(cases--){
    cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;

    if (xright < xleft)
      swap(xright, xleft);
    if (ytop < ybottom)
      swap(ytop, ybottom);

    Point seg_start, seg_end, left_bottom, left_top, right_bottom, right_top;
    seg_start.x = xstart;
    seg_start.y = ystart;
    seg_end.x = xend;
    seg_end.y = yend;
    left_bottom.x = xleft;
    left_bottom.y = ybottom;
    left_top.x = xleft;
    left_top.y = ytop;
    right_bottom.x = xright;
    right_bottom.y = ybottom;
    right_top.x = xright;
    right_top.y = ytop;

    if (inter(seg_start, seg_end, left_top, left_bottom) ||
            inter(seg_start, seg_end, left_top, right_top) ||
            inter(seg_start, seg_end, right_bottom, left_bottom) ||
            inter(seg_start, seg_end, right_bottom, right_top))
        cout << "T" << endl;
    else if(xstart >= xleft && xstart <= xright && ystart >= ybottom && ystart <= ytop)
      cout << "T"<< endl;
    else if(xend >= xleft && xend <= xright && yend >= ybottom && yend <= ytop)
      cout << "T"<< endl;
    else
      cout << "F" << endl;

  }

  return 0;
}
