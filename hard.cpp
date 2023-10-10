#include <iostream>
#include <string.h>
#define SIZE 200
using namespace std;

void truyVet(char A[], char B[], int L[][SIZE], int m, int n, int x, char maxStr[]);
void MAXNUMBER_HARD(char A[], char B[]);
void chuanhoa(char A[], char B[]);
void chenso0(char S[], int n);
void xoaSo0dau(char S[]);

int main() {
    char A[SIZE],B[SIZE];
    gets(A);
    gets(B);
    MAXNUMBER_HARD(A,B);
}
void MAXNUMBER_HARD(char A[], char B[]){
    int m = strlen(A);
    int n = strlen(B);
    int L[SIZE][SIZE];
    for (int i=0; i<=m; i++)
         L[i][0] = 0;
    for (int i=0; i<=n; i++) 
        L[0][i] = 0;
    for (int i=1; i<=m; i++) 
        for (int j=1; j<=n; j++) 
            if (A[i-1]==B[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]);
    char maxStr[SIZE] = " ";
    int x = L[m][n];
    if(x==0)
    	cout<<-1;
	else{
        for(int i=m; i>0; i--){
            for (int j=n; j>0; j--){
                if(L[i][j]<=x){
                    truyVet(A,B,L,i,j,x,maxStr);
                }
            }
        }
        puts(maxStr);
	}
}
void truyVet(char A[], char B[], int L[][SIZE], int m, int n, int x, char maxStr[]){
    char S[SIZE];
    int dem = 0;
    while (m>0 && n>0) {
        if (A[m-1]==B[n-1]){
            S[dem++] = A[m-1];
            m--;
            n--;
        }
        else if (L[m-1][n]>L[m][n-1])
            m--;
        else
            n--;
    }
    S[dem] = '\0';
    strrev(S);
    // xoa so 0 thua
    xoaSo0dau(S);
    chuanhoa(S,maxStr);
    if(strcmp(S,maxStr)>0)
        strcpy(maxStr,S);
}
void xoaSo0dau(char S[]){
	strrev(S);
	int i=strlen(S)-1;
	while(i>=0 && S[i]=='0')
		i--;
	S[i+1] = '\0';
	strrev(S);
}
void chuanhoa(char A[], char B[]){
	int lenA = strlen(A);
	int lenB = strlen(B);
	if(lenA>lenB)
		chenso0(B,lenA-lenB);
	else
		chenso0(A,lenB-lenA);
}
void chenso0(char S[], int n){
	strrev(S);
	int len = strlen(S);
	for(int i=0; i<n; i++)
		S[len+i] = '0';
	S[len+n] = '\0';
	strrev(S);
}
