#include <bits/stdc++.h>
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    pair<int , int> m[n];
    for(int i = 0; i < n; i++){
        m[i].first = end[i];
        m[i].second = i;
    }

    sort(m , m + n);
    int ans = 1;
    int limit = m[0].first;
    for(int i = 1; i < n; i++){
        if( start[m[i].second] > limit){
            limit = m[i].first;
            ans++;
        }
    }
    return ans;
}



same complexity

#include <bits/stdc++.h>
struct meeting{
    int s;
    int e;
    int p;
};


bool comp (struct meeting m1 , struct meeting m2){
    if(m1.e < m2.e)return true;
    else if(m2.e < m1.e)return false;
    else if(m1.p < m2.p)return true;
    return false;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    struct meeting m[n];
    for(int i = 0; i < n; i++){
        m[i].s = start[i];
        m[i].e = end[i];
        m[i].p = i + 1;
    }

    sort(m , m + n, comp);
    int answer = 1;
    int limit = m[0].e;
    for(int i = 1; i < n; i++){
        if(m[i].s > limit){
            limit = m[i].e;
            answer++;
        }
    }
    return answer;
}
