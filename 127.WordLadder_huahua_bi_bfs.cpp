// Author: Huahua
// running time: 32ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        int len = beginWord.length();

        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};

        int step = 0;

        while (!q1.empty() && !q2.empty()) {
            ++step;

            // always expand the smaller queue first: q1
            if (q1.size() > q2.size())
                std::swap(q1, q2);

            unordered_set<string> q;

            for (string w : q1) {
                for (int i=0; i<len; ++i) {
                    char ch = w[i];
                    for (int j='a'; j<='z'; ++j) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }

            std::swap(q, q1);
        }
        return 0;
    }
}
