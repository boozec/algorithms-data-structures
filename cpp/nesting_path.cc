// Google Code Jam 2020
#include<iostream>

using namespace std;

void findall(string & data, string to_search, string replace_str) {
    size_t pos = data.find(to_search);

    while(pos != string::npos) {
        data.replace(pos, to_search.size(), replace_str);
        pos = data.find(to_search, pos + replace_str.size());
    }
}


string get_s2(const string& s) {
    string s2{};
    int index{};
    bool toa = true;
    for(int i = 0; i < s.length(); ++i) {    
        int n = (s[i]-'0');
        if(toa) {
            for(int j = 0; j < n; ++j) {
                s2.insert(index++, "(");
            }
        }
        s2 += (n+'0');
        ++index;
        if(s[i+1] != s[i]) {
            toa = true;
            for(int j = 0; j < n; ++j) {
                s2.insert(index++, ")");
            }
        } else {
            toa = false;
        }
    }

    while(s2.find(")(") != string::npos || s2.find("()") != string::npos) {
        findall(s2, ")(", "");
        findall(s2, "()", "");
    }

    return s2;
}

int main() {
    int N;
    cin >> N;

    for(int _ = 0; _ < N; ++_) {
        string s;
        cin >> s;

        cout << "Case #" << _+1 << ": " << get_s2(s) << endl;
    }
    return 0;
}
