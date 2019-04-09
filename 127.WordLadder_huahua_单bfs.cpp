// Author: Huahua
// running time: 93 ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(). wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int len = beginWord.length();
        int step = 0;

        while (!q.empty()) {
            ++step;  // 很好表示了中间的连接步长
            for (int size = q.size(); size>0; size--) {
                string w = q.front();
                q.pop();
                for (int i=0; i<len; ++i) {
                    char ch = w[i];
                    for (int j = 'a'; j<='z'; ++j) {
                        w[i] = j;
                        // Found solution
                        if (w == endWord) return step + 1;
                        // Not in dict, skip
                        if (!dict.count(w)) continue;
                        // Remove new word from dict
                        dict.erase(w);
                        // Add new word into queue
                        q.push(w);
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
}
