#include <stdio.h>
#include <math.h>

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
    // Dlugosci odcinkow:
    // Odcinek AB
    double dlugoscAB = sqrt(pow((r1.p2->x - r1.p1->x),2) + pow((r1.p2->y - r1.p1->y), 2));

    // Odcinek BC
    double dlugoscBC = sqrt(pow((r1.p3->x - r1.p2->x), 2) + pow((r1.p3->y - r1.p2->y), 2));

    // Odcinek CD
    double dlugoscCD = sqrt(pow((r1.p4->x - r1.p3->x), 2) + pow((r1.p4->y - r1.p3->y), 2));

    // Odcinek DA
    double dlugoscDA = sqrt(pow((r1.p1->x - r1.p4->x), 2) + pow((r1.p1->y - r1.p4->y), 2));

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
