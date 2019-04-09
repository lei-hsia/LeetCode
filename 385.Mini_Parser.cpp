class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if (s.size()<=2) return NestedInteger();
        NestedInteger res;
        int start =1; count = 0;
        for (int i=1; i<s.size(); ++i) {
            if (count==0 && (s[i]=="," || i==s.size()-1)) {
                res.add(deserialize(s.substr(start, i-start)));
                start = i+1;
            } else if (s[i]=='[') ++count;
            else --count;
        }
        return res;
    }
}

// this is the interace allowing for createing nested lists
class NestedInteger {
public:
    // Constructor initializes an empty nested lists
    NestedInteger();

    NestedInteger(int value);

    bool isInteger() const;

    int getInteger() const;

    // set this NestedInteger to hold a single integer
    void setInteger(int value);

    // set this NestedInteger to hold a nested list and adds
    // a nested integer to it.
    void add(const NestedInteger &ni);

    const vector<NestedInteger> &getList() const;
};
