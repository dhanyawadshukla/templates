#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void merge(vector<long long> &v, long long start, long long mid, long long end, long long &x) {
    long long l1 = start;
    long long l2 = mid + 1;
    vector<long long> temp;

    while (l1 <= mid and l2 <= end) {
        if (v[l1] <= v[l2]) {
            temp.push_back(v[l1]);
            l1++;
        } else {
            temp.push_back(v[l2]);
            x += (mid - l1 + 1);
            l2++;
        }
    }

    while (l1 <= mid) {
        temp.push_back(v[l1]);
        l1++;
    }

    while (l2 <= end) {
        temp.push_back(v[l2]);
        l2++;
    }

    for (long long i = 0; i < temp.size(); i++) {
        v[start + i] = temp[i];
    }
}

void mergesort(vector<long long> &v, long long start, long long end, long long &x) {
    if (start < end) {
        long long mid = start + (end - start) / 2;
        mergesort(v, start, mid, x);
        mergesort(v, mid + 1, end, x);
        merge(v, start, mid, end, x);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, long long>> v;
        for (int i = 0; i < n; i++) {
            long long a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        vector<long long> x;
        for (auto i : v) {
            x.push_back(i.second);
        }
        long long y = 0;
        mergesort(x, 0, n - 1, y);
        cout << y << endl;
    }
}
