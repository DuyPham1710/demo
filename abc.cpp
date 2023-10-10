#include <bits/stdc++.h>
using namespace std;
int n;
long long F[1000][1000]={0};
int main(){
    fstream input("input.txt", ios::in);
    fstream out("output.txt", ios::out);
    if (!input){
        cout << "Khong doc duoc file !\n";
        return 0;
    }
    input>>n;
    input.close();
    int nA = 0;
	int sum = n*(n+1)/2;
    if(sum%2!=0)
        out << 0;
    else{
        F[0][0] = 1;
        for (int i=1; i<=n; i++){
            for (int j=0; j<=sum/2; j++){
                F[i][j] = F[i-1][j];
                if(j>=i)
                    F[i][j] += F[i-1][j-i];
            }
        }
        out << F[n][sum/2]/2 << endl;
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<=sum/2; j++)
            out << F[i][j] << "\t";
        out << "\n";
    }
    out.close();
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <unordered_set>

// using namespace std;

// const int MAXN = 5e5 + 5;
// const int MAXQ = 5e5 + 5;
// const int MAX_VALUE = 1e9 + 5;

// struct Query {
//     int left, right, index;
// };

// int blockSize;
// vector<int> a(MAXN);
// vector<int> result(MAXQ);
// unordered_set<int> distinctNumbers;

// void add(int number) {
//     distinctNumbers.insert(number);
// }

// void remove(int number) {
//     distinctNumbers.erase(number);
// }

// bool cmp(const Query &a, const Query &b) {
//     int blockA = a.left / blockSize;
//     int blockB = b.left / blockSize;
//     if (blockA != blockB) {
//         return blockA < blockB;
//     }
//     return a.right < b.right;
// }

// int main() {
//     int n, Q;
//     cin >> n >> Q;

//     blockSize = static_cast<int>(sqrt(n));
//     vector<Query> queries;

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     for (int i = 0; i < Q; i++) {
//         int L, R;
//         cin >> L >> R;
//         queries.push_back({L - 1, R - 1, i});
//     }

//     sort(queries.begin(), queries.end(), cmp);

//     int left = 0, right = -1;

//     for (const Query &query : queries) {
//         while (left > query.left) {
//             left--;
//             add(a[left]);
//         }
//         while (right < query.right) {
//             right++;
//             add(a[right]);
//         }
//         while (left < query.left) {
//             remove(a[left]);
//             left++;
//         }
//         while (right > query.right) {
//             remove(a[right]);
//             right--;
//         }

//         int smallestMissing = 0;
//         while (distinctNumbers.count(smallestMissing) > 0) {
//             smallestMissing++;
//         }

//         result[query.index] = smallestMissing;
//     }

//     for (int i = 0; i < Q; i++) {
//         cout << result[i] << endl;
//     }

//     return 0;
// }
