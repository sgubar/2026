typedef struct Node
{
    char value;
    struct Node *next;
} Node;

Node *CreateNode(char value);
void DeleteNode(Node *node);
void PrintNode(Node *node);

typedef struct List
{
    Node *head;
} List;

List *CreateList();
void DeleteList(List *list);
void PrintList(List *list);
int RemoveElementById(List *list, int id);
int InsertToListById(List *list, int id, char value);
int AppendToList(List *list, char value);