Brute Force Approach

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > 2 * nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};


Optimal Approach

class Solution {
private:
    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }


        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &nums, int low, int mid, int high){
        int count = 0;
        int right = mid + 1;
        for(int i = low ; i <= mid; i++){
            while(right <= high && nums[i] > (2LL*nums[right])){
                right++;
            }
            count += right - (mid + 1);
        }
        return count;
    }

    int mergeSort(vector<int> &nums, int low, int high){
        int count = 0;
        if(low == high){
            return count;
        }

        int mid = (low + high) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};
