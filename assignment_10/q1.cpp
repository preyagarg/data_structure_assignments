#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int n : nums) {
        if (seen.count(n)) {
            return true; // found duplicate
        }
        seen.insert(n);
    }

    return false; // no duplicates
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << (containsDuplicate(nums) ? "true" : "false");
    return 0;
}
