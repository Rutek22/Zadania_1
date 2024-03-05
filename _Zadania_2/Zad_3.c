#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;
}Point;

typedef struct {
    Point* p1;
    Point* p2;
    Point* p3;
    Point* p4;
}Rectangle;

//Przesunięcie
void move_point(Point* p) {
    p->x++;
    p->y++;
}

//Pole
int rectangle_area(Rectangle r) {
    int x = r.p3->x - r.p2->x;
    int h = r.p4->y - r.p3->y;

    return x * h;
}

//Obwód
int rectangle_circuit(Rectangle r) {
    int ab = r.p2->y - r.p1->y;
    int ac = r.p3->x - r.p1->x;
    int cd = r.p4->y - r.p3->y;
    int bd = r.p4->x - r.p2->x;
    return ab + ac + cd + bd;
}

int main()
{
    Point p = { 1,4 };
    printf("Przed: x=%d, y=%d\n", p.x, p.y);
    move_point(&p);
    printf("Po: x=%d, y=%d\n", p.x, p.y);

    Point p1 = { 2, 2 };
    Point p2 = { 2, 5 };
    Point p3 = { 7, 2 };
    Point p4 = { 7, 5 };

    Rectangle r = { &p1, &p2, &p3, &p4 };

    printf("Punkty prostokata r: p1(%d, %d), p2(%d, %d), p3(%d, %d), p4(%d, %d)\n",
           r.p1->x, r.p1->y, r.p2->x, r.p2->y, r.p3->x, r.p3->y, r.p4->x, r.p4->y);
    printf("Pole: %d\n", rectangle_area(r));
    printf("Obwod: %d\n", rectangle_circuit(r));

    return 0;
}
