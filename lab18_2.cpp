#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap( Rect *rect1,  Rect *rect2) {

    double overlapX1 = max(rect1->x, rect2->x);
    double overlapY1 = max(rect1->y - rect1->h, rect2->y - rect2->h);

    double overlapX2 = min(rect1->x + rect1->w, rect2->x + rect2->w);
    double overlapY2 = min(rect1->y , rect2->y );

    double overlapWidth = max(0.0, overlapX2 - overlapX1);
    double overlapHeight = max(0.0, overlapY2 - overlapY1);

    double overlapArea = overlapWidth * overlapHeight;

    return overlapArea;
}

int main() {

    Rect rect1 = {1, 1, 5, 5};
    Rect rect2 = {2, 2, 5, 5};

    double area = overlap(&rect1, &rect2);

    cout <<  area << "\n";

    return 0;
}