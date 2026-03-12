typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

Node *CreateNode(int value);
void DeleteNode(Node *node);
void PrintNode(Node *node);

typedef struct List
{
    Node *head;
    Node *tail;
} List;

List *CreateList();
void DeleteList(List *list);
void PrintList(List *list);
int AppendToList(List *list, int value);
void Sort(List *list);
Node *FindMin(List *list);
Node *FindMax(List *list);