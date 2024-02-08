Brute Force Approach

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            nums.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            nums.push_back(nums2[j]);
            j++;
        }

        if(nums.size()%2 == 1){
            return (double)nums[nums.size()/2];
        }
        return (nums[nums.size()/2] + nums[nums.size()/2-1]) / 2.0;
    }
};


Better Approach

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int i = 0;
        int j = 0;

        int cnt = 0;
        int s1e = -1;
        int s2e = -1;

        while(i < s1 && j < s2){
            if(nums1[i] <= nums2[j]){
                if(cnt == (s1 + s2)/2) s1e = nums1[i];
                if(cnt == ((s1 + s2)/2 - 1)) s2e = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == (s1 + s2)/2) s1e = nums2[j];
                if(cnt == ((s1 + s2)/2 - 1)) s2e = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i < s1){
            if(cnt == (s1 + s2)/2) s1e = nums1[i];
            if(cnt == ((s1 + s2)/2 - 1)) s2e = nums1[i];
            cnt++;
            i++;
        }

        while(j < s2){
            if(cnt == (s1 + s2)/2) s1e = nums2[j];
            if(cnt == ((s1 + s2)/2 - 1)) s2e = nums2[j];
            cnt++;
            j++;
        }


        if((s1 + s2)%2 == 1){
            return s1e;
        }
        else{
            return (s1e + s2e) / 2.0;
        }
    }
};


Optimal Approach

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        if(n1 > n2){
            return findMedianSortedArrays(b, a);
        }
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;

        int low = 0;
        int high = n1;

        while(low <= high){
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;

        }
        return 0;

        
    }
};
