typedef struct tagNode
{
    double value;
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
void InsertDouble(Tree *tree, double ch);
void PrintTree(Tree *tree);
void PrintFullTree(Tree *tree);
void DeleteNodeByDouble(Tree *tree, double ch);
Node *FindNodeByDouble(Tree *tree, double ch);