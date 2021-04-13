#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> zeros(int n) {
    int a = pow(2,n);
    vector<string> ret;
    for(int i=0;i<a; i++) {
        ret.push_back(string(a,'0'));
    }
    return ret;
}

vector<string> add(vector<string> a, vector<string> b) {
    vector<string> ret;
    for(int i=0; i<a.size(); i++) {
        ret.push_back(a[i] + b[i]);
    }
    return ret;
}

vector<string> matrix(int n) {
    if(n == 1) return {"01", "11"};
    vector<string> m0 = add(zeros(n-1), matrix(n-1));
    vector<string> mp = add(matrix(n-1), matrix(n-1));
    vector<string> m;
    m.reserve(m0.size() + mp.size());
    m.insert(m.end(), m0.begin(), m0.end());
    m.insert(m.end(), mp.begin(), mp.end());
    return m;
}

int main() {
    int n;
    cin>>n;
    vector<string> ret = matrix(n);
    int size = ret.size();
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
        cout <<ret[i][j] << ' ';
        }
        cout << endl;
    }
}