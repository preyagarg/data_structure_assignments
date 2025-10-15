#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class FirstNonRepeating {
private:
    queue<char> q;
    unordered_map<char, int> freq;

public:
    void processStream(const string &str) 
{
        for (char ch : str) 
        {
          freq[ch]++;
            q.push(ch);
            while (!q.empty() && freq[q.front()] > 1) 
            {
                q.pop();
            }
            if (q.empty())
                cout << -1 << " ";
            else
                cout << q.front() << " ";
        }
        cout << endl;
    }
};

int main() {
    string s;
    cout << "Enter string (space separated characters): ";
    getline(cin, s);
    string clean;
    for (char c : s)
        if (c != ' ')
            clean += c;

    FirstNonRepeating obj;
    obj.processStream(clean);

    return 0;
}
