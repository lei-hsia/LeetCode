// bfs: 改变一个char, 先看行不行，把有可能的都放到queue中,
// 而不是dfs一条路走到黑
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        unordered_map<string, int> pathCount({{beginWord, 1}});
        queue<string> q({beginWord});
        while (!q.empty()) {
            string word = q.front(); q.pop();
            // newWord是要改变一个char之后的单词,初始化为word
            for (int i=0; i<word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch<= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord==endWord) return pathCount[word]+1;
                    if (wordSet.count(newWord) && !pathCount.count(newWord)) {
                        // 说明变到的当前的 word在map中没有,那么这个中间状态的的单词加入要bfs遍历的queue中
                        q.push(newWord);
                        // 同时这个新的中间状态的单词加入path中, 伴随改变的次数是上一个单词加一次
                        pathCount[newWord] = pathCount[word]+1;
                    }
                }
            }
        }
        return 0;
    }
}
