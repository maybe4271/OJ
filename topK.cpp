#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iterator>

using namespace std;

struct compare
{
    bool operator()(map<string, int>::iterator left, map<string, int>::iterator right)
    {
        return left->second < right->second;
    }
};



int main()
{
    map<string, int> hm;
    string s;
    int k = 2;
    for (int i = 0; i < 10; i++) {
        cin >> s;
        hm[s]++;
    }

    priority_queue<map<string, int>::iterator, vector<map<string, int>::iterator>, compare> pq;
    map<string, int>::iterator it = hm.begin();

    while (it != hm.end()) {
        pq.push(it);
        ++it;
    }

    while(k--) {
        cout << pq.top()->first << " " << pq.top()->second << endl;
        pq.pop();
    }
    return 0;
}
