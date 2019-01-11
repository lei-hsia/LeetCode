
// 不用 sort, 每一个string对应自己的ID string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // first:char次数转化的字符串; second: anagrams
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            vector<int> count(26, 0); // 每个词中每个char出现的次数
            string countChar = "";
            for (char c : str) count[c-'a']++;
            for (int i : count) countChar += to_string(i);
            map[countChar].push_back(str);
        }
        
        for (auto a : map) {
            res.push_back(a.second);
        }
        return res;
    }
};


// 用sort: anagrams都得到相同的string 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};
