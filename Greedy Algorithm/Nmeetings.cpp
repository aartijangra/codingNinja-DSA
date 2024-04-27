// Maximum meetings
// Problem statement
// You are given the schedule of 'N' meetings with their start time 'Start[i]' and end time 'End[i]'.
// You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.
// Note:
// The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting.
// For example:
// 'N' = 3, Start = [1, 3, 6], End = [4, 8, 7].

// You can organize a maximum of 2 meetings. Meeting number 1 from 1 to 4, Meeting number 3 from 6 to 7.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6
// 1 3 0 5 8 5
// 2 4 6 7 9 9
// Sample Output 1:
// 4
// Explanation For Sample Input 1:
// You can organize a maximum of 4 meetings: 

// Meeting number 1 from 1 to 2.
// Meeting number 2 from 3 to 4.
// Meeting number 4 from 5 to 7.
// Meeting number 5 from 8 to 9.
// Sample Input 2:
// 5
// 0 7 1 4 8
// 2 9 5 9 10
// Sample Output 2:
// 2 
// Constraints:
// 1 <= 'N' <= 10^5
// 0 <= 'Start[i]' < 'End[i]' <= 10^9

// Time Limit: 1 sec

#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator (struct meeting m1, meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    struct meeting meet[n];
    for(int i=0; i<n; i++){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i+1;
    }

    sort(meet, meet+n, comparator);
    vector<int> ans;

    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for(int i=1; i<n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans.size();
}