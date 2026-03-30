#include<stdio.h>

typedef struct{
    int x;
    int y;
}point_t;

typedef struct{
    point_t center;
    int radius;
}circle_t;

typedef struct{
    circle_t c1;
    circle_t c2;
}concentric_circles_t;

int main(){
    concentric_circles_t cc;
    cc.c1.center.x = 0;
    cc.c1.center.y = 0;
    cc.c1.radius = 5;
    cc.c2.center.x = 0;
    cc.c2.center.y = 0;
    cc.c2.radius = 10;

    
    concentric_circles_t *ptrCC = &cc; 
    circle_t *ptrC1 = (circle_t*)&cc; // same as (circle_t*)&cc.c1
    point_t *ptrP1 = (point_t*)&cc; // same as (point_t*)&cc.c1.center.x
    int *ptrX = (int*)&cc; // same as (int*)&cc.c1.center.x
    
    
    printf("ptrCC:  %lu \n", ptrCC); // Accessing the address of the concentric_circles_t structure
    printf("ptrC1:  %lu \n", ptrC1); // Accessing the address of the first circle structure
    printf("ptrP1:  %lu \n", ptrP1); // Accessing the address of the point structure of the center of the first circle
    printf("ptrX : %lu \n", ptrX); // Accessing the address of the x coordinate of the center of the first circle
}
