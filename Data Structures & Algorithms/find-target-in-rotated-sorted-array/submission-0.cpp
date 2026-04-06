class Solution {
public:

    int binSearch(vector<int>& nums, int start, int end, int target){
        
        while(start <= end){
            int mid = (start+end)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r){
            int mid = (l+r)/2;

            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        int ans1 = binSearch(nums, 0, r-1, target);
        int ans2 = binSearch(nums, r, nums.size()-1, target);

        return ans1 == -1 ? ans2 : ans1;
    }
};
