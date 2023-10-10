#include <iostream>
#define MAX 100
using namespace std;

struct Queue{
    int A[MAX];
    int front;
    int rear;
};

bool isFullQueue(Queue &a);

int main(){

}

void EnQueue(Queue a, int x){
    if (isFullQueue(a))
        cout << "Queue is Full\n";
    else{
        if (a.rear==MAX-1){
            for (int i=a.front; i<=a.rear; i++){
                a.A[i-a.front] = a.A[i];
            }
            a.rear = a.rear - a.front;
            a.front = 0;
        }
        if(a.front==-1)
            a.front++;
        a.rear++;
        a.A[a.rear] = x;
    }
}

int DeQueue(Queue a){
    if (isEmpty(a))
        return;
    int tmp = a.A[a.front];
    a.front++;
    if (a.front>a.rear)
        initQueue(a);
    return tmp;
}

bool isEmpty(Queue a){
    return a.front==-1 && a.rear==-1;
}

bool isFullQueue(Queue &a){
    return a.rear>=MAX-1;
}

void initQueue(Queue &a){
    a.front = -1;
    a.rear = -1;
}