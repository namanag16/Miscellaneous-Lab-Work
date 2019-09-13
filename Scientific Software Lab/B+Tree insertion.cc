// This program implements B+ Tree insertion


#include <iostream>
#include <stdlib.h>
#include <queue>

#define ORDER 3

using namespace std;

struct btree{
    short no_of_keys;
    bool leaf;
    int arr_keys[ORDER-1];
    struct btree *chd_ptr[ORDER];
    struct btree *parent;
};

struct btree *Tree;

bool allocateNode(struct btree *T);
void insertBTree(struct btree *x,int key,struct btree *left,struct btree *right);
void splitLeaf(struct btree *x,struct btree *node,int key);
void splitNonLeaf(struct btree *x,struct btree *node,int *key,struct btree *left,struct btree *right);
struct btree* findNodeX(struct btree *x,int key);
void viewBTree(struct btree *T);

int main()
{

    int key;
    char flag;
    bool ret;
    cout << "The order of B+ tree is assumed to be 4 throughout" << endl;
    cout << "Initializing tree.. " << endl;
    cout << Tree << endl;
    ret = allocateNode(Tree);
    if(ret == true)
    {    cout << "Initializing tree.. done" << endl; }
    else
    {    cout << "failed in createBTree.. exiting" << endl; exit(1); }

    struct btree *x;
    cout << "initial keys: " << Tree->no_of_keys << endl;

label:
    cout << "Enter a key to be inserted: ";
    cin >> key;
    x = findNodeX(Tree,key);
    insertBTree(x,key,NULL,NULL);
    viewBTree(Tree);
    cout << endl;
    cout << "continue(c) / exit(e): ";
    cin >> flag;
    if(flag == 'c')
        goto label;


}

bool allocateNode(struct btree *T)
{

    Tree = new struct btree;
    if(Tree == NULL)
    {
        return false;
    }
    Tree->no_of_keys = 0;
    Tree->leaf = true;
    cout << "allocated new node " << endl;
    return true;
}

void insertBTree(struct btree *x,int key,struct btree *left,struct btree *right)
{
    //if(x->leaf == true)
    //{
        if(x->no_of_keys < ORDER-1) // insert the key in this node itself
        {
                //starting from index i shift keys to the right
                cout << "in insert non full" << endl;
                int i = x->no_of_keys;
                int j = i-1;
                x->arr_keys[i] = key;

                if(x->leaf == true)
                {
                    cout << "inserting into leaf " << i << " " << j << endl;
                    for(;x->arr_keys[j] > x->arr_keys[i] && j>=0;i--,j--) //swap until j-th key is greater than i-th key
                    {
                            cout << "did come at shift " << endl;
                            x->arr_keys[j] = x->arr_keys[i] + x->arr_keys[j] - (x->arr_keys[i] = x->arr_keys[j]);
                    }


                    x->no_of_keys +=1;


                    x->chd_ptr[x->no_of_keys] = x->chd_ptr[(x->no_of_keys)- 1];
                    x->chd_ptr[(x->no_of_keys)- 1] = NULL;
                }
                else
                {
                    cout << "inserting into non leaf " << i << " " << j << endl;
                    for(;x->arr_keys[j] > x->arr_keys[i] &&  j>=0;i--,j--) //swap until j-th key is greater than i-th key
                    {
                            x->arr_keys[j] = x->arr_keys[i] + x->arr_keys[j] - (x->arr_keys[i] = x->arr_keys[j]);
                            x->chd_ptr[i+1] = x->chd_ptr[i]; // handles child pointers
                    }

                    x->no_of_keys +=1;

                    x->chd_ptr[i] = left;
                    x->chd_ptr[i+1]= right;
                }


        }
        else //find middle key .. split current node .. insert middle key to parent
        {
            /*i=0;
            while(i < (x->no_of_keys))
            {
                if(key < x->arr_keys[i])
                {
                    break;
                }
                i++;
            }*/
            cout << "in insert full " << endl;
            if(x->leaf == true)
            {
                //split the current node and distribute two keys to the left and two to the right
                struct btree *node;
                allocateNode(node);
                splitLeaf(x,node,key);

                cout << "split leaf successfull " << endl;
                //call insert on parent and recurse
                if(x->parent == NULL)
                {
                    struct btree *root;
                    allocateNode(root);
                    root->leaf = false;
                    root->parent = NULL;
                    x->parent = node->parent = root;
                    Tree = root; // update root of the tree
                    cout << "jus splitted root.. recursing" << endl;
                    insertBTree(x->parent,x->arr_keys[(x->no_of_keys)-1],x,node);
                }
                else
                {
                    cout << "splitted non root .. recursing " << endl;
                    insertBTree(x->parent,x->arr_keys[(x->no_of_keys)-1],x,node);
                }
            }
            else
            {
                struct btree *node;
                allocateNode(node);
                node->leaf = false;
                splitNonLeaf(x,node,&key,left,right);
                cout << "split non leaf successfull" << endl;
                if(x->parent == NULL)
                {
                    struct btree *root;
                    allocateNode(root);
                    root->leaf = false;
                    root->parent = NULL;
                    x->parent = node->parent = root;
                    Tree = root; // update root of the tree
                    cout << "splitted root.. recursing" << endl;
                    insertBTree(x->parent,key,x,node);
                }
                else
                {
                    cout << "jus splitted non root .. recursing " << endl;
                    insertBTree(x->parent,key,x,node);
                }
            }
            /*if(i==1)
            {
                if(x->parent == NULL)
                {
                    struct btree *p;
                    allocateNode(p);
                    p->leaf == false;


                }
            }*/

        }
    //}




}

void splitLeaf(struct btree *x,struct btree *node,int key) // split x into two .. x will be left and node will be right
{
        //find actual positions of keys
        cout << "in split leaf" << endl;
        int arr[ORDER];
        int i;
        cout << "-2";
        for(i =0;i < x->no_of_keys;i++)
        {
            arr[i] = x->arr_keys[i];
        }
        cout << "-1";
        int j = i-1;
        arr[i] = key;
        cout << "0";
        for(;arr[j] > arr[i] && j>=0;i--,j--) //swap until j-th key is greater than i-th key
        {
                arr[j] = arr[i] + arr[j] - (arr[i] = arr[j]);
        }
        cout << "1 ";
        int p;
        for(p=0;p<((ORDER+1)/2)/*((ORDER/2)+(ORDER%2))*/;p++)
        {
            x->arr_keys[p]=arr[p];
        }
        cout << "2 ";
        int a;
        int c = p;
        for(a=0;c<ORDER;c++)
        {
            node->arr_keys[a++] = arr[c];
        }
        cout << "3 ";

        node->no_of_keys = a;
        x->no_of_keys = p;
        node->parent = x->parent;
        node->chd_ptr[a] = x->chd_ptr[ORDER-1];
        x->chd_ptr[p] = node;
        cout << "leaving from split leaf " << endl;

}

void splitNonLeaf(struct btree *x,struct btree *node,int *key,struct btree *left,struct btree *right)
{
    //find actual positions of keys
        cout << "in split non leaf" << endl;
        int arr[ORDER];
        struct btree *ptr[ORDER+1];
        int i;

        for(i =0;i < x->no_of_keys;i++)
        {
            arr[i] = x->arr_keys[i];
            ptr[i] = x->chd_ptr[i];
        }

        int j = i-1;
        arr[i] = *key;
        ptr[i] = x->chd_ptr[i];

        //prepare arr and child pointer array
        for(;arr[j] > arr[i] && j>=0;i--,j--) //swap until j-th key is greater than i-th key
        {
                arr[j] = arr[i] + arr[j] - (arr[i] = arr[j]);
                ptr[i+1] = ptr[i];
        }
        ptr[i]=left;
        ptr[i+1] = right;

        //start making node x (left)
        int p;
        for(p=0;p<((ORDER-1)/2);p++)
        {
            x->arr_keys[p]=arr[p];
            x->chd_ptr[p] = ptr[p];
        }

        x->chd_ptr[p] = ptr[p]; // set one remaining child ptr

        //skip the p-th key in arr and copy rest into right node
        int a;
        int c = p+1;
        for(a=0;c<ORDER;c++)
        {
            node->arr_keys[a] = arr[c];
            node->chd_ptr[a++] = ptr[c];
            //put child pointers here
        }
        node->chd_ptr[a] = ptr[c]; // set one remaining child ptr
        node->no_of_keys = a;
        x->no_of_keys = p;

        // to_do update the parent pointer of the children as well
        node->parent = x->parent;
        *key = arr[p];
        cout << "leaving from split non leaf" << endl;

}

struct btree * findNodeX(struct btree *x,int key)
{
        cout << "in find node "  << endl;
        int i;
        if(x->no_of_keys == 0)
        {
            cout << "first insert.. leaving from find node" << endl;
            return x;
        }
        for(i=0;i < (x->no_of_keys);i++)
        {
            if(x->arr_keys[i] > key )
                break;
        }
        if(x->leaf == false)
        {
            findNodeX(x->chd_ptr[i],key);
        }
        else
        {
            cout << "leaving from find node" << x->arr_keys[0] << " " << x->no_of_keys << endl;
            return x;
        }


}

void viewBTree(struct btree *x)
{

    cout << "in view btree..#keys: " << x->no_of_keys << endl;
    queue<struct btree*> myqueue;


    if(x->no_of_keys == 0)
    {
        cout << "returning" << endl;
        return;
    }

    myqueue.push(x);
    while(!myqueue.empty())
    {
        struct btree *y = myqueue.front();
        myqueue.pop();
        int i;
        for(i=0;i < y->no_of_keys;i++)
        {
            cout << y->arr_keys[i] << "   ";
            if(y->leaf == false)
            {
                myqueue.push(y->chd_ptr[i]);
            }
        }
        if(y->leaf == false)
        {
            myqueue.push(y->chd_ptr[i]);
        }

        cout << endl;
    }

    cout << "leaving from view btree" << endl;


}
