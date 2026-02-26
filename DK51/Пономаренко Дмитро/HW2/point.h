typedef struct tagPoint
{
    int x;
    int y;
} Point, *PPoint;

Point *CreatePoint(int x, int y);
void DestroyPoint(Point *p);
void PrintPoint(Point *p);