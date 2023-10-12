#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int data;
    NODE* left;
    NODE* right;
};

struct TREE{
    NODE* root;
};

void postOrder(NODE* root);
void inOrder(NODE* root);
void preOrder(NODE* root);
void Add(NODE* &root, int x);
NODE* SearchOnTree(NODE* root, int x);
int DeleteNode(NODE* root, int x);
void deleteAll(NODE* &root);
NODE* createNode(int x);

int a[100], n;
int main(){
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    TREE tr;
    tr.root = NULL;
    for (int i=0; i<n; i++){
        Add(tr.root, a[i]);
    }
    preOrder(tr.root);
    cout << endl;
    NODE* p = SearchOnTree(tr.root, 3);
    cout << p->data << endl;
    // inOrder(tr.root);
    // cout << endl;
    // postOrder(tr.root);
    // cout << endl;
    // DeleteNode(tr.root, 4);
    // preOrder(tr.root);
    // deleteAll(tr.root);
    return 0;
}

void xoaLa(NODE* root, int x){
    if (root->left==NULL)
        return;
    else if (root->data > x)
        xoaLa(root->left, x);
    else if  (root->data < x)
        xoaLa(root->right, x);
    else{
        NODE* p = root;
        root = NULL;
        delete p;
    }
}

int DeleteNode(NODE* root, int x){
    if (root==NULL)
        return 0;
    if (root->data > x)
        DeleteNode(root->left, x);
    if (root->data < x)
        DeleteNode(root->right, x);
    NODE* tmp;
    if (root->left==NULL){
        tmp = root;
        root = root->right;
        delete tmp;
    }
    else{
        if (root->right==NULL){
            tmp = root;
            root = root->left;
            delete tmp;
        }
        else{   // trường hợp có đầy đủ 2 con
            NODE* p;
            for (p=root->right; p->left!=NULL; p=p->left);
            tmp = p;
            root->data =p->data;
            p=p->right;
            delete tmp;
        }
    }
    return 1;
}

NODE* SearchOnTree(NODE* root, int x){
    NODE* p = root;
    while (p!=NULL){
        if (p->data==x)
            return p;
        else if (p->data > x)
            p=p->left;
        else if (p->data < x)
            p=p->right;
    }
    return NULL;
}

NODE* createNode(int x){
    NODE* root = new NODE;
    if (root==NULL)
        return NULL;
    else{
        root->data = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
}
void Add(NODE* &root, int x){
    if (root!=NULL){
        if (root->data==x)
            return;
        if (root->data > x)
            return Add(root->left, x);
        if (root->data < x)
            return Add(root->right, x);   
    }
    else{
        root = createNode(x);
    }
}

void preOrder(NODE* root){
    if (root!=NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(NODE* root){
    if (root!=NULL){
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }
}

void postOrder(NODE* root){
    if (root!=NULL){
        preOrder(root->left);
        preOrder(root->right);
        cout << root->data << " ";
    }
}

void deleteAll(NODE* &root){
    if (root != NULL){
        deleteAll(root->left);
        deleteAll(root->right);
        delete root;
    }
}