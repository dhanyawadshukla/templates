#include <bits/stdc++.h>
using namespace std;

void pnc(string up, string p, vector<string> &v) {
    if (up == "") {
        v.push_back(p);
        return;
    }

    for (int i = 0; i < up.size(); i++) {
        char c = up[i];
        string rest = up.substr(0, i) + up.substr(i + 1);
        pnc(rest, p + c, v);
    }
}

int main() {
    string a = "abc";
    vector<string> v;
    pnc(a, "", v);
    for (auto i : v) {
        cout << i << endl;
    }
    return 0;
}
