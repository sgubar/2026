#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometry.h"

// ======[[MATH]]====== //
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

// ======[[VECTOR2]]====== //

vec2* createVec2(const float x,const float y) {
    vec2* vector = (vec2*)malloc(sizeof(vec2));
    if (vector == NULL) return NULL;

    vector->x = x;
    vector->y = y; 

    return vector;

}

void deleteVec2(vec2* vector) {
    if (vector != NULL) 
    free(vector);
};

// ======[[CIRCLES]]====== //

circle* createCircleFromArray(const float* array) {
    if (array == NULL) return NULL;

    circle* circ = createCircleFromCords(array[0],array[1], array[2],array[3]);
    if (circ == NULL) return NULL;

    return circ;
};

circle* createCircleFromVectors(const vec2* position,const vec2* radius) {
    if (position == NULL || radius == NULL) return NULL;

    circle* circ = createCircleFromCords(position->x, position->y, radius->x, radius->y);
    if (circ == NULL) return NULL;

    return circ;
};
circle* createCircleFromCords(const float posx, const float posy, const float radx, const float rady) {

    circle* circ = (circle*)malloc(sizeof(circle));

    if (circ == NULL) return NULL;

    circ->position = createVec2(posx,posy);
    circ->radius = createVec2(radx,rady);

    return circ;
};
int getCircleScale(circle* circ) {
    return PI * (float)circ->radius->x * (float)circ->radius->y;
};

void printCircleInfo(circle* circ) {
    float posx  = (float)circ->position->x;
    float posy  = (float)circ->position->y;
    float radx  = (float)circ->radius->x;
    float rady  = (float)circ->radius->y;
    float scale = (float)getCircleScale(circ);

    if (radx == rady) {
        printf("Коло:\nПозиція: %.2f %.2f\nрадіус кола: %.2f\nПлоща: %.2f\n", posx, posy,rady,scale);
    } else {
        printf("Еліпс:\nПозиція: %.2f %.2f\nРадіус малої піввісі: %.2f\nРадіус великої піввіс: %.2f\nПлоща: %.2f\n", posx, posy,min(radx,rady),max(radx,rady),scale);
    }
};

void deleteCircle(circle* circ) {
    deleteVec2(circ->position);
    deleteVec2(circ->radius);
    free(circ);
};

// ======[[CIRCLES ARRAY]]====== //

circleArray* createCircleArray(const unsigned int maxLength) {
    circleArray* circlesarray = (circleArray*)malloc(sizeof(circleArray));
    if (circlesarray == NULL) return NULL;

    circle** circles = (circle**)malloc(sizeof(circle*) * (maxLength));
    if (circles == NULL) {deleteCircleArray(circlesarray); return NULL;}

    circlesarray->circles = circles;

    circlesarray->arrayLength = 0;
    circlesarray->maxLength = maxLength;
    return circlesarray;
};

int pushCircleToArray(circleArray* circles,circle* circ) {
    if (circles == NULL || circ == NULL) return -1;
    if (circles->arrayLength >= circles->maxLength) return -1;

    circles->circles[circles->arrayLength] = circ;
    circles->arrayLength++;
    return 0;
};

int insertCircleToArray(circleArray* circles, circle* circ, const unsigned int index) {
    if (circles == NULL || circ == NULL) return -1;
    if (index >= circles->maxLength) return -1;

    deleteCircle(circles->circles[index]);

    circles->circles[index] = circ;

    return 0;
};

circle* popCircleFromArray(circleArray* circles) {
    if (circles == NULL) return NULL;
    
    circles->arrayLength--;

    circle* poppedItem = circles->circles[circles->arrayLength];
    circles->circles[circles->arrayLength] = NULL;

    return poppedItem;
};


void printCircleArray(const circleArray* circles) {
    if (circles == NULL) return;


    for (int i = 0;i < circles->arrayLength;i++) {
        printf("№%d\n", i);
        printCircleInfo(circles->circles[i]);
    }

};

void deleteCircleArray(circleArray* circles) {
    for (int i = 0;i < circles->arrayLength;i++) {
        deleteCircle(circles->circles[i]);
    }
    free(circles->circles);
    free(circles);
};
