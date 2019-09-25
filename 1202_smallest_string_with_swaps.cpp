这道题出的真的很好, 我做完了有一种“能做这么好的题真是幸福”的感觉... 

/*
neal_wu的做法: 是把union_find作为一个DS单独写成struct, 之后每次要union_find的时候直接用这个就行了
其实下面这个就是做了三件事: init初始化, find(), unite(); 这里的unite是有返回值bool类型, 这里是用不
到的，但是其他的地方可能会用到
*/

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;
    
    union_find(int n = 0) {
        if (n > 0) init(n);
    }
    
    void init(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        components = n;
        
        for (int i = 0; i <=n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) return false;
    
        if (size[x] < size[y]) swap(x, y);
        
        parent[y] = x;
        // UF对象中的每个components的size, 这里并没有用到, 但是可能有用
        size[x] += size[y]; 
        components--;
        return true;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        union_find uf(n);
        
        for (vector<int> &p : pairs)
            uf.unite(p[0], p[1]);
        
        vector<vector<int>> components(n, vector<int>());
        
        // 遍历s,把所有的index对应的元素都放在不同的components中
        // 每一个component中放的是所有联通的位置的index
        for (int i = 0; i < n; ++i) {
            components[uf.find(i)].push_back(i);
        }
        
        for (vector<int> &c : components) {
            string chars;
            
            for (int index : c) 
                chars += s[index];
            
            sort(chars.begin(), chars.end());
            
            for (int i = 0; i < (int) c.size(); ++i) 
                s[c[i]] = chars[i];
        }
        
        return s;
    }
};
