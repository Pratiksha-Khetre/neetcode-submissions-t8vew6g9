class Solution {
public:

    int daysUsed(vector<int>& weights, int num){
        int curr_weight = 0;
        int days = 1;

        for(int w : weights){
            if(curr_weight + w > num){
                days ++;
                curr_weight = w;
            }
            else{
                curr_weight += w;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i : weights){
            sum += i;
        }

        int mini = *max_element(weights.begin() , weights.end());

        int start = mini;
        int end = sum;
        int ans = 0;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int cal = daysUsed(weights, mid);

            if(cal <= days){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};