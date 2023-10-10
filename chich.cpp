#include<iostream>
using namespace std;

void quickSort(long long A[], int L[], int R[], int l, int r);

long long A[500];
int L[500], R[500], n, q;
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> L[i] >> R[i];
    }
    quickSort(A,L,R,0,n-1);
    for (int i = 0; i< n; i++)
    {
        cout << A[i];
    }
}
void quickSort(long long A[], int L[], int R[], int l, int r)
{
    int i = l, j = r;
    long long x = A[(l+r)/2];
    while(i<=j){
        while (A[i] < x)
            i++;
        while (A[j] > x)
            j--;
        if (i<=j){
            swap(A[i], A[j]);
            swap(L[i], L[j]);
            swap(R[i], R[j]);
            i++;
            j--;
        }
    }
    if (l<j)
        quickSort(A, L, R, l, j);
    if (r>i)
        quickSort(A, L, R, i, r);
}