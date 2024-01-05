Brute Force approach

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int left = 0;
        int right = 0;

        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
                temp.push_back(nums2[right]);
                right++;
            }
        }

        while(left < m){
            temp.push_back(nums1[left]);
            left++;
        }

        while(right < n){
            temp.push_back(nums2[right]);
            right++;
        }

        int p = temp.size();
        for(int i = 0; i < p; i++){
            nums1[i] = temp[i];
        }
    }
};



Optimal Approach


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = 0;
        while(left >= 0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        for(int i = 0; i < n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
