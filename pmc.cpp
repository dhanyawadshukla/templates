#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;
        int z = 0;
        bool r = false;

        for(int i=0;i<10;i++){
            if (x.find(s) != string::npos) {
            r = true;
            break;
        }
            else{
                x+=x;
                z++;
            }
        }

        

        if (r) {
            cout << z << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
