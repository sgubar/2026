typedef struct tagNode
{
    char value;
    struct tagNode *left;
    struct tagNode *right;
} Node;

void PrintNode(Node *node);
void DestroyNode(Node *node);

typedef struct tagTree
{
    struct tagNode *root;
    int count;
} Tree;

Tree *CreateTree();
void DestroyTree(Tree *tree);
void InsertChar(Tree *tree, char ch);
void PrintTree(Tree *tree);
void PrintFullTree(Tree *tree);
Node *FindNodeByChar(Tree *tree, char ch);