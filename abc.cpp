#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Query {
    int left, right, index;
};

int a[MAXN];
int result[MAXN];
int freq[2 * MAXN];
int smallestAbsent = 1;

bool cmp(Query a, Query b) {
    int blockSize = sqrt(MAXN);
    if (a.left / blockSize != b.left / blockSize) {
        return a.left / blockSize < b.left / blockSize;
    }
    return a.right < b.right;
}

void add(int x) {
    freq[x]++;
    while (freq[smallestAbsent] > 0) {
        smallestAbsent++;
    }
}

void remove(int x) {
    freq[x]--;
    if (x < smallestAbsent) {
        smallestAbsent = x;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].index = i;
    }

    sort(queries.begin(), queries.end(), cmp);

    int currentLeft = 1, currentRight = 0;

    for (Query query : queries) {
        int left = query.left;
        int right = query.right;

        while (currentLeft < left) {
            remove(a[currentLeft]);
            currentLeft++;
        }

        while (currentLeft > left) {
            add(a[currentLeft - 1]);
            currentLeft--;
        }

        while (currentRight < right) {
            add(a[currentRight + 1]);
            currentRight++;
        }

        while (currentRight > right) {
            remove(a[currentRight]);
            currentRight--;
        }

        result[query.index] = smallestAbsent;
    }

    for (int i = 0; i < q; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
