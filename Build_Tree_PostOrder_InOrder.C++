#include <iostream>
using namespace std;
struct Node
{
    int Data;
    struct Node *Left;
    struct Node *Right;
    Node(int Value)
    {
        Data = Value;
        struct Node *Left = NULL;
        struct Node *Right = NULL;
    }
};
int search(int InOrder[], int First, int Last, int Current)
{
    for (int i = First; i <= Last; i++)
    {
        if (InOrder[i] == Current)
        {
            return i;
        }
    }
    return -1;
}
struct Node *Build_Tree(int InOrder[], int PostOrder[], int First, int Last)
{
    if (First > Last)
    {
        return NULL;
    }
    static int Index = 2;
    int Current = PostOrder[Index];
    Index--;
    struct Node *root = new Node(Current);
    int Position = search(InOrder, First, Last, Current);
    if (First == Last)
    {
        return root;
    }
    root->Left = Build_Tree(InOrder, PostOrder, First, Position - 1);
    root->Right = Build_Tree(InOrder, PostOrder, Position + 1, Last);
    return root;
}
void InOrder_Traversal(struct Node * root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder_Traversal(root->Left);
    cout<<root->Data<<" ";
    InOrder_Traversal(root->Right);
}
void PostOrder_Traversal(struct Node * root)
{
    if(root == NULL)
    {
        return;
    }
    PostOrder_Traversal(root->Left);
    PostOrder_Traversal(root->Right);
    cout<<root->Data<<" ";

}
int main()
{
    struct Node *root;
    int InOrder[] = {2, 1, 3};
    int PostOrder[] = {2, 3, 1};
    root = Build_Tree(InOrder, PostOrder, 0, 2);
    InOrder_Traversal(root);
    cout<<endl;
    PostOrder_Traversal(root);
    return 0;
}