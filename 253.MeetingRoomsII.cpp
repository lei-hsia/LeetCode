struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
}

// 用map
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a.start]; --m[a.end];
        }
        int res = 0, rooms = 0;
        for (auto it : m) {  // map是按照key排序的
            res = max(res, rooms += it.second);
        }
    }
}

// 用一个pq
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
          return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto a : intervals) {
            if (!pq.empty() || pq.top() <= a.start) pq.pop();
            pq.push(a.end);
        }
        return pq.size();
    }
}
