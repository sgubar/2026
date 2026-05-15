#pragma once

#define PI 3.141592

// ======[[VECTOR2]]====== //

typedef struct vec2 {
    float x;
    float y;
} vec2;

vec2* createVec2(float x, float y);
void deleteVec2(vec2* vector);

// ======[[CIRCLES]]====== //

typedef struct circle {
    vec2* position;
    vec2* radius;
} circle;

circle* createCircleFromArray(const float* array);
circle* createCircleFromVectors(const vec2* position,const vec2* radius);
circle* createCircleFromCords(const float posx, const float posy, const float radx, const float rady);

int getCircleScale(circle* circ);

void printCircleInfo(circle* circ);

void deleteCircle(circle* circle);

// ======[[CIRCLES ARRAY]]====== //

typedef struct circleArray {
    int maxLength;
    int arrayLength;
    circle** circles;
} circleArray;

circleArray* createCircleArray(const unsigned int maxLength);

int pushCircleToArray(circleArray* circles,circle* circ);
int insertCircleToArray(circleArray* circles, circle* circ, const unsigned int index);


circle* popCircleFromArray(circleArray* Menu);

void printCircleArray(const circleArray* circles);

void deleteCircleArray(circleArray* circles);