// bfs: 改变一个char, 先看有没有可能作为potential中间状态的单词,
// 把可能的都放在queue中, 而不是dfs一条路走到黑
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q({beginWord});
        unordered_map<string, int> pathCount({{beginWord, 1}});
        while (!q.empty()) {
            string word = q.front(); q.pop();
            // newWord是改变word的一个char之后的单词，初始化为word
            for (int i=0; i<word.size(); ++i) {
                string newWord = word;
                for (char ch='a'; ch<='z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord==endWord) return pathCount[word]+1;
                    if (wordSet.count(newWord) && !pathCount.count(newWord)) {
                        q.push(newWord);
                        pathCount[newWord] = pathCount[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
}
