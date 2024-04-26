#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Counter {
private:
    std::map<int, int> counts;

public:
    Counter() {}

    Counter(const std::vector<int>& vec) {
        for (int num : vec) {
            counts[num]++;
        }
    }

    std::vector<std::pair<int, int> > most_common(int n) {
        std::vector<std::pair<int, int> > sorted_counts(counts.begin(), counts.end());
        std::sort(sorted_counts.begin(), sorted_counts.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        if (n < sorted_counts.size()) {
            sorted_counts.resize(n);
        }
        return sorted_counts;
    }

    void update(const std::vector<int>& vec) {
        for (int num : vec) {
            counts[num]++;
        }
    }

    std::vector<int> flatten() {
        std::vector<int> flattened;
        for (const auto& pair : counts) {
            for (int i = 0; i < pair.second; ++i) {
                flattened.push_back(pair.first);
            }
        }
        return flattened;
    }

    int operator[](int key) const {
        return counts.count(key) ? counts.at(key) : 0;
    }

    std::map<int, int> get_map() const {
        return counts;
    }
};

int main() {
    Counter c({1, 2, 2, 2, 4});

    std::map<int, int> initial_map = c.get_map();
    for (const auto& pair : initial_map) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

    c.update({2, 6, 4, 1});

    std::map<int, int> updated_map = c.get_map();
    for (const auto& pair : updated_map) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

    std::vector<int> flattened = c.flatten();
    for (int num : flattened) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "c[5] = " << c[5] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    return 0;
}
