//
// Created by Сергей on 23.03.2024.
//

// This Sort for 1<=n<10^5 and nums for sort <= 10^4
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> count1(10001,0);
    vector<int> count2(10001,0);
    for (int i = 0; i < n; ++i) {
        if (nums[i] >= 0) {
            count1[nums[i]]++;
        } else {
            count2[abs(nums[i])]++;
        }
    }
    for (int i = 10000; i >= 0; i--) {
        for (int j = 0; j < count2[i]; ++j) {
            cout << -i << " ";
        }
    }
    for (int i = 0; i <= 9999 + 1; i++) {
        for (int j = 0; j < count1[i]; ++j) {
            cout << i << " ";
        }
    }
}
