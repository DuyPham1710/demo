#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector <long long> &A, vector <long long> &B, int l, int r);

int main(){
    long long m, n, k;
    cin >> m >> n >> k;
    vector <long long> A(k+1);
    vector <long long> B(k+1);
    long long tmp = 0;
    for (int i=0; i<k; i++){
        cin >> A[i] >> B[i];
        if ((A[i]==1 && (B[i]==1 || B[i]==n)) || (A[i]==m && (B[i]==1 || B[i]==n))){
            if (m>1 && n>1)
                tmp += 2;
            else
                tmp += 1;
        }
        // nếu là điểm ở canh khac goc
        else if (A[i]==1 || B[i]==1 || A[i]==m || B[i]==n){
            if (m>1 && n>1)
                tmp += 3;
            else
                tmp += 2;
        }
        else{
            tmp += 4;
        }
    }
    QuickSort(A, B, 0, k-1);
    int x = 0;
    for (int i=0; i<k; i++){
        if (A[i]!=A[i+1]){
            QuickSort(B, A, x, i);
            x = i+1;
        }
    }
    for (int i=0; i<k; i++){
		if(A[i]==A[i+1] && B[i]+1==B[i+1])
			tmp--;
	}
	QuickSort(B, A, 0, k-1);
	x = 0;
	for(int i=0; i<k; i++){
		if(B[i]!=B[i+1]){
			QuickSort(A, B, x, i);
			x = i+1;
		}
	}
	for(int i=0; i<k; i++){
		if(B[i]==B[i+1] && A[i]+1==A[i+1])
			tmp--;
	}
    long long  tong = (n-1)*m+(m-1)*n;
    cout << tong - tmp;
    return 0;
}

void QuickSort(vector <long long> &A, vector <long long> &B, int l, int r){
	int i=l,j=r;
	long long pivot=A[(l+r)/2];
	while(i<=j){
		while(A[i]<pivot)
			i++;
		while(A[j]>pivot)
			j--;
		if(i<=j){
			swap(A[i],A[j]);
			swap(B[i],B[j]);
			i++;
			j--;
		}
	}
	if(j>l)
		QuickSort(A, B, l, j);
	if(i<r)
		QuickSort(A, B, i, r);
}