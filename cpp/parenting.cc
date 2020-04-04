// Google Code Jam 2020
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
    using ti = tuple<int, int, int>;
    int T;
    cin >> T;

    for(int _ = 0; _ < T; ++_) {
        int N;
        cin >> N;
        char* s = new char[N];
        bool check{true};
        ti qq;
        priority_queue<ti, vector<ti>, greater<ti>> q;
        for(int i = 0; i < N; ++i) {
           int e1, e2;
           cin >> e1 >> e2;
           get<0>(qq) = e1;
           get<1>(qq) = e2;
           get<2>(qq) = i;
           q.push(qq);
        }

        int bounds[2] {0, 0};

        while(!q.empty()) {
            int start = get<0>(q.top());
            int end = get<1>(q.top());
            int index = get<2>(q.top());

            if(bounds[0] <= start) {
                bounds[0] = end;
                s[index] = 'C';
            } else if(bounds[1] <= start) {
                bounds[1] = end;
                s[index] = 'J';
            } else {
                check = false;
                break;
            }
            q.pop();
        }

        cout << "Case #" << _+1 << ": ";
        if(check) {
            for(int i = 0; i < N; ++i)
                cout << s[i];
        } else {
            cout << "IMPOSSIBLE";
        }

        cout << endl;
        delete[] s; 
    }

    return 0;
}
