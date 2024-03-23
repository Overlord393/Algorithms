//
// Created by Сергей on 22.03.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int m_el = num[i];
        int index_min = i;

        bool flag = false;
        for (int j = i + 1; j < n; ++j) {
            if (num[j] < m_el) {
                m_el = num[j];
                index_min = j;
                flag = true;
            }
        }
        if (flag) {
        swap(num[index_min], num[i]);

        }
    }
    for (int c : num) {
        cout << c << " ";
    }
}