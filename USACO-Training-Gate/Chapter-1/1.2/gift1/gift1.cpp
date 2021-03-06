/*
ID: jadDebugs
TASK: gift1
LANG: C++
*/                

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

void setIO(string name = "") {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("gift1");

    int n; cin >> n;

    unordered_map<string, int> names;
    string arr[n];

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        names[str] = 0;
        arr[i] = str;
    }

    while (true) {
        string name;
        if (!(cin >> name))
            break;
        int money, ppl; cin >> money >> ppl;
        for (int i = 0; i < ppl; i++) {
            string str; cin >> str;
            names[str] += money/ppl;
            names[name] -= money/ppl;
        }
    }

    for (string x: arr)
        cout << x << ' ' << names[x] << '\n';

    return 0;
}
