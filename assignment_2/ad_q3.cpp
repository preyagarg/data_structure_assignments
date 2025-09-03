#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AnagramChecker {
private:
    string str1, str2;

public:
    AnagramChecker(const string& s1, const string& s2) : str1(s1), str2(s2) {}

    bool areAnagrams() {
        if (str1.length() != str2.length()) return false;

        string sorted1 = str1;
        string sorted2 = str2;

        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());

        return sorted1 == sorted2;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    AnagramChecker checker(s1, s2);
    if (checker.areAnagrams()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
