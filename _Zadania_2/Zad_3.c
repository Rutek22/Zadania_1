#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* p1;
    Point* p2;
    Point* p3;
    Point* p4;
}Rectangle;

void funkcja(Point* p) {
    p->x++;
    p->y++;
}

void funkcja2(Rectangle r1) {
    int dlugoscAB = r1.p1->y - r1.p2->y;
    int dlugoscBC = r1.p3->x - r1.p2->x;
    int dlugoscCD = r1.p4->y - r1.p3->y;
    int dlugoscDA = r1.p4->x - r1.p1->x;

    double obw = dlugoscAB + dlugoscBC + dlugoscCD + dlugoscDA;
    double pole = dlugoscAB * dlugoscBC;

    printf("Obwod figury: %f\n", obw);
    printf("Pole figury: %f\n", pole);
}

int main()
{
    Point p1 = { 0, 4 };
    Point p2 = { 0, 0 };
    Point p3 = { 4, 0 };
    Point p4 = { 4, 4 };

    Rectangle r1 = { &p1, &p2, &p3, &p4 };

    printf("Point p1: %d:%d\n", p1.x, p1.y);

    funkcja(&p1);

    printf("Point p1 po uzyciu funkcji: %d:%d\n", p1.x, p1.y);

    funkcja2(r1);

    return 0;
}
