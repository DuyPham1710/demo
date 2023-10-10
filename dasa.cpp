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
int a[100], n;
int main(){
    fstream in("input.txt", ios::in);
    if(!in){
		cout<<"Khong the doc file";
		return 0;
	}
    
    in >> n;
    for (int i=0; i<n; i++)
        in >> a[i];
    in.close();
    TREE tr;
    tr.root = NULL;
    tr.root->left = NULL;
    tr.root->right = NULL;
    tr.root->data = a[0];
    for (int i=1; i<n; i++)
        Add(tr.root, a[i]);
    return 0;
}
int Add(NODE* root, int x){
    if (root!=NULL){
        if (root->data==x)
            return 0;
        else if (root->data > x)
            return Add(root->left, x);
        else if (root->data < x)
            return Add(root->right, x);   
    }
}

