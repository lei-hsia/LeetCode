class Solution {
    def partition(self, s):
        '''
        :type s: str
        :rtype List[List[str]]
        全局变量或者方法就用self. 如果不是就不加self.
        那么就只是在局部方法作用域内
        '''
        self.res= []
        self.dfs(s, [])
        return self.res

    def dfs(self, s, temp):
        # Return Condition
        if not s:
            self.res.append(temp[:])
            return
        # Backtracking
        for i in xrange(1, len(s)+1):
            if self.isPali(s[:i]):
                temp.append(s[:i])
                self.dfs(s[i:], temp)
                temp.pop()

    def isPali(self, s):
        return s == s[::-1]
}
