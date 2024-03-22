//
// Created by Сергей on 22.03.2024.
//
#include "iostream"
#include "vector"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i < n; ++i) {
        int pos = i;
        while (pos > 0 && num[pos-1] > num[pos]) {
            swap(num[pos], num[pos-1]);
            pos--;
        }
    }
    for (int c : num) {
        cout << c << " ";
    }
}
