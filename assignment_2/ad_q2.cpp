#include <iostream>
#include <string>

using namespace std;

class StringSplitter {
private:
    string s;

    bool isSubstring(const string& str, const string& sub) {
        return str.find(sub) != string::npos;
    }

public:
    StringSplitter(const string& input) : s(input) {}

    bool canSplit() {
        int n = s.size();

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string A = s.substr(0, i);
                string B = s.substr(i, j - i);
                string C = s.substr(j);

                if (!B.empty() && isSubstring(A, B) && isSubstring(C, B)) {
                    return true;
                }
                if (!A.empty() && isSubstring(B, A) && isSubstring(C, A)) {
                    return true;
                }
                if (!C.empty() && isSubstring(A, C) && isSubstring(B, C)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    string input;
    cin >> input;

    StringSplitter splitter(input);
    if (splitter.canSplit()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

