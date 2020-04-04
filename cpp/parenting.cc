// Google Code Jam 2020
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

short find_free(const vector<bool>& c, const vector<bool>& j, int ii, int jj) {
    // 0 = c
    // 1 = j
    bool skip{true};
    for(int i = ii; i < jj; ++i) {
        if(!c.at(i)) {
            skip = false;
            break;
        }
    }

    if(skip) return 0;

    for(int i = ii; i < jj; ++i) {
        if(!j.at(i)) {
            return -1;
        }
    }

    return 1;
}

bool sortpair(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first + a.second < b.first + b.second && (a.first < a.second || b.first < b.second));
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, int>> p;
    for(int _ = 0; _ < T; ++_) {
        int N;
        cin >> N;

        p.clear();
        string s;
        vector<bool> _c(24*60+1, true);
        vector<bool> _j(24*60+1, true);
        for(int i = 0; i < N; ++i) {
           int e1, e2;
           cin >> e1 >> e2;
           p.push_back({e1, e2});
        }

        for(int i = 0; i < N; ++i) {
            int index1 = p[i].first;
            int index2 = p[i].second;
            int who = find_free(_c, _j, index1, index2);
            switch(who) {
            case 0:
                {
                    s += "C";
                    for(int j = index1; j < index2; ++j) _c[j] = false;
                    break;
                }
            case 1:
                {
                    s += "J";
                    for(int j = index1; j < index2; ++j) _j[j] = false;
                    break;
                }
            }
            if(who == -1) {
                s = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << _+1 << ": " << s << endl;
    }

    return 0;
}
