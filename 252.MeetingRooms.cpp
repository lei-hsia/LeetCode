struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
}

// 1. 自定义sort排序之后直接比较
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval& b) {
          return a.start < b.start;
        });
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};

// 2. 不定义sort直接比较
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
          for (int i=0; i<intervals.size(); ++i) {
              for (int j=0; j<intervals.size(); ++j) {
                  if ((intervals[i].start<intervals[j].start && intervals[i].end>intervals[j].start) ||
                      (intervals[i].start>intervals[j].start && intervals[j].end>intervals[i].start))
                      return false;
              }
          }
          return true;
    }
};
