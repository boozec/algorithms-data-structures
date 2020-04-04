// Google Code Jam 2020
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int get_trace(const vector<vector<int>>& m) {
    int sum{};
    for(int i = 0; i < m.size(); ++i) {
        sum += m.at(i).at(i);
    }

    return sum;
}

int get_dupl_row(const vector<vector<int>>& m) {
    int nums{};
    vector<int> elem;
    for(int i = 0; i < m.size(); ++i) {
        elem.clear();
        for(int j = 0; j < m.size(); ++j) {
            if(find(begin(elem), end(elem), m[i][j]) == elem.end()) {
                elem.push_back(m[i][j]);
            } else {
                nums++;
                break;
            }
        }
    }
    return nums;
}

int get_dupl_column(const vector<vector<int>>& m) {
    int nums{};
    vector<int> elem;
    for(int i = 0; i < m.size(); ++i) {
        elem.clear();
        for(int j = 0; j < m.size(); ++j) {
            if(find(begin(elem), end(elem), m[j][i]) == elem.end()) {
                elem.push_back(m[j][i]);
            } else {
                nums++;
                break;
            }
        }
    }
    return nums;
}

int main() {
    int T;
    cin >> T;

    for(int _ = 0; _ < T; ++_) {
        int N;
        cin >> N;
        vector<vector<int>> matrix;
        for(int i = 0; i < N; ++i) {
            matrix.push_back(vector<int>{});
            int elem;
            for(int j = 0; j < N; ++j) {
                cin >> elem;
                matrix.at(i).push_back(elem);
            }
        }
        cout << "Case #"<< _+1<<": " <<  get_trace(matrix) << ' ' << get_dupl_row(matrix) << ' ' << get_dupl_column(matrix) << endl;
    }

    return 0;
}
