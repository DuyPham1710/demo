#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int data;                   
    NODE *next;
};

struct LIST{                                  
    NODE *head;
    NODE *tail;
};

bool search(LIST a, int x);
bool isEmptyList(LIST a);
void AddFirst(LIST &a, NODE* p);
void AddLast(LIST &a, NODE* p);
void AddNode(LIST &a, NODE* p, NODE* q);
NODE* createNode(int x);
void initList(LIST &myList);
void RemoveFirst(LIST &a);
void RemoveLast(LIST &a);
void RemoveNode(LIST &a, NODE* q);
void xoa(LIST &a, int x);
void QuickSort(LIST &a);

int main(){
    LIST a;
    initList(a);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        NODE* p = createNode(x);
        AddLast(a, p);
    }
    QuickSort(a);
    for (NODE* i=a.head; i!=NULL; i=i->next)
        cout << i->data << " ";
    cout << endl;
    // NODE* p = createNode(10);
    // AddFirst(a, p);
    // NODE* p1 = createNode(20);
    // AddLast(a, p1);
    // NODE* p2 = createNode(30);
    // AddNode(a, p2, p);
    // for (NODE* i=a.head; i!=NULL; i=i->next)
    //     cout << i->data << " ";
    // cout << endl; 
    // int x;
    // cin >> x;
    // xoa(a, x);
    // for (NODE* i=a.head; i!=NULL; i=i->next)
    //     cout << i->data << " ";
    // cout << endl;
    return 0;
}

void QuickSort(LIST &a){
    LIST list1, list2;
    NODE* pivot, *p;
    initList(list1);
    initList(list2);
    /*Trường hợp danh sách rỗng hoặc có 1 phần tử*/ 
    if(a.head==a.tail)
        return;
    /*Phân hoạch danh sách thành 2 danh sách con*/ 
    pivot = a.head;
    p = a.head->next;
    while (p!=NULL){
        NODE* q = p;
        p=p->next;
        q->next = NULL;
        if (q->data < pivot->data)
            AddLast(list1, q);  //Thêm vào cuối danh sách 1 
        else
            AddLast(list2, q); //Thêm vào cuối danh sách 2 

    }
    //Gọi đệ quy sắp xếp cho các danh sách con 
    QuickSort(list1);
    QuickSort(list2);
    //Ghép nối danh sách 1 + pivot 
    if (!isEmptyList(list1)){
        a.head = list1.head;
        list1.tail->next = pivot; 
    }
    else
        a.head = pivot;
    //Ghép nối pivot + danh sách 2 
    pivot->next = list2.head;
    if(!isEmptyList(list2))
        a.tail = list2.tail;
    else
        a.tail = pivot;
}

void xoa(LIST &a, int x){
    if(a.head==NULL)
        cout << "Khong xoa duoc !\n";
    else if(x==a.head->data)
        RemoveFirst(a);
    else{
        NODE* i = a.head;
        while(i!=NULL){
            if(i->data==x)
                break;
            i=i->next;
        }
        if(i==NULL)
            cout << "x does not exist !!\n";
        else{
            NODE* p;
            for (p=a.head; p->next!=i; p=p->next);
            RemoveNode(a, p);
        }
    }
}

void RemoveNode(LIST &a, NODE* q){
    if(a.head==a.tail || q==a.tail){
        cout << "Khong xoa duoc phan tu sau q\n";
        return;
    }
    NODE* p = q->next;
    q->next = p->next;
    if (p==a.tail)
        a.tail = q;
    delete p;
}

void RemoveLast(LIST &a){
    if(isEmptyList(a))
        cout << "Danh sach rong\n";
    else{
        NODE* tmp = a.tail;
        if(a.head==a.tail)
            a.head = a.tail = NULL;
        else{
            NODE* p;
            for (p=a.head; p->next!=a.tail; p=p->next);
            p->next = NULL;
            a.tail = p;
        }
        delete tmp;
    }
}

void RemoveFirst(LIST &a){
    if(isEmptyList(a))
        cout << "Danh sach rong\n";
    else{
        NODE* p = a.head;
        if(a.head==a.tail)
            a.head = a.tail = NULL;
        else
            a.head = a.head->next;
        delete p;
    }
}

void AddNode(LIST &a, NODE* p, NODE* q){
    p->next = q->next;
    q->next = p;
    if(a.tail==q)
        a.tail = p;
}

void AddFirst(LIST &a, NODE* p){
    if(isEmptyList(a))
        a.head = a.tail = p;
    else{
        p->next = a.head;
        a.head = p;
    }
}

void AddLast(LIST &a, NODE* p){
    if(isEmptyList(a))
        a.head = a.tail = p;
    else{
        a.tail->next = p;
        a.tail = p;
    }
}

NODE* createNode(int x){
    NODE* tmp = new NODE;
    if(tmp==nullptr )
        return nullptr;
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

bool search(LIST a, int x){
    for (NODE* i=a.head; i!=NULL; i=i->next)
        if(i->data==x)
            return true;
    return false;
}

void initList(LIST &myList){
    myList.head = myList.tail = NULL;
}

bool isEmptyList(LIST a){
    return a.head==NULL;
}