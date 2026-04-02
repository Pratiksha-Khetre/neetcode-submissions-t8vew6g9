class Solution {
public:

    int speed(vector<int>& piles, int num){
        int ans = 0;
        for(int a : piles){
            if(a <= num){
                ans++;
            }
            else{
                ans += (a + num - 1) / num;
            }
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int start = 1;
        int end = maxi;
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int sum = speed(piles, mid);

            if(sum <= h){
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
