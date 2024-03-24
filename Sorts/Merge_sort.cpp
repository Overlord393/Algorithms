//
// Created by Сергей on 24.03.2024.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(const vector<int>& a, const vector<int>& b) {
    auto iter1 = a.begin();
    auto iter2 = b.begin();
    vector<int> c(a.size() + b.size());
    for (size_t i = 0; i < c.size(); ++i) {
        if (iter1  == a.end() && iter2 != b.end()) {
            c[i] = *iter2;
            iter2++;
            continue;
        } else if (iter2 == b.end() && iter1 != a.end()) {
            c[i] = *iter1;
            iter1++;
            continue;
        } else {
            c[i] = min(*iter1, *iter2);
        }
        if (c[i] == *iter1) {
            iter1++;
        } else {
            iter2++;
        }
    }
    return c;
}
vector<int> Merge_sort(const vector<int>& a) {
    auto mid = a.begin() + a.size()/2;
    std::vector<int> firstHalf(a.begin(), mid);
    std::vector<int> secondHalf(mid, a.end());
    if (firstHalf.size() == 1 && secondHalf.size() == 1) {
        return merge(firstHalf, secondHalf);
    }
    if (firstHalf.size() == 1) {
        return merge(firstHalf, Merge_sort(secondHalf));
    }
    if (secondHalf.size() == 1) {
        return merge(Merge_sort(firstHalf), secondHalf);
    }
    return merge(Merge_sort(firstHalf), Merge_sort(secondHalf));
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0];
    } else {
        a = Merge_sort(a);
        for (int item : a) {
            cout << item << " ";
        }
    }
}