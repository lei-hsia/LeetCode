AddressSanitizer: heap-buffer-overflow on address 0x610000000100 at pc 0x000000408272 bp 0x7fff3278e710 sp 0x7fff3278e708
其实这个思路还是比较清晰, 但是超过了xxx ?
```
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int m = words.size(), n = puzzles.size();
        vector<int> res(n, 0);
        
        vector<vector<int>> w(m, vector<int>(26, 0));
        for (int i = 0; i < m; ++i) {
            for (string word : words) {
                for (char c : word) {
                    w[i][c-'a'] = 1;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            vector<int> contain(26, 0);
            for (char c : puzzles[i]) {
                contain[c-'a'] = 1;
            }
            
            for (int j = 0; j < m; ++i) {
                if (w[j][puzzles[i][0]-'a'] == 0) continue;
                
                for (int k=0; k<26; ++k) {
                    if (contain[k] < w[j][k]) break;
                    if (k == 25 && contain[k] >= w[j][k]) count++;
                }
            }
            res[i] = count;
        }
        
        return res;
        
    }
};
```
