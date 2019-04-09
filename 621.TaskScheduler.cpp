class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 用pq做，太巧的方法没有实战意义
        // m: 记录每个char对应的任务的数量
        // pq: 任务数量从大到小排列,因为按照从多到少的顺序处理
        // t: vector用来表示每次能处理的任务的数量,每个格子塞进一个不同的任务
        int res = 0, cycle = n+1;
        unordered_map<char, int> m;
        priority_queue<int> pq;
        for (char c : tasks) ++m[c];
        for (auto &a: m) pq.push(a.second);
        while (!q.empty()) {
            int count = 0;
            vector<int> t;
            for (int i=0; i < cycle; ++i) {
                if (!q.empty()) {
                    t.push_back(q.top()); q.pop();
                    ++count;
                }
            }
            for (int i : t) {
                if (--i > 0) q.push(i);
            }
            res += q.empty()? count : cycle;
        }
        retunr res;
    }
}
