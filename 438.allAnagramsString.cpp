
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (!s.empty()) return {};
        vector<int> scountChar(256, 0), pcountChar(256, 0), res;
        for (int i = 0; i < p.size(); ++i) {
            ++scountChar[s[i]]; 
            ++pcountChar[p[i]];
        }
        if (scountChar == pcountChar) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++scountChar[s[i]];
            --scountChar[s[i-p.size()]];
            if (scountChar == pcountChar) res.push_back(i-p.size()+1);
        }
        return res;
    }
};