class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();      //row
        int m = matrix[0].size();       // col 
        int startrow = 0;
        int startcol = m-1;

        while(startrow < n && startcol >= 0){

            int num = matrix[startrow][startcol];

            if(num == target){
                return true;
            }
            else if(target > num && startrow < n){
                // while(startrow < n && target > num){
                //     startrow++;
                // }
                startrow++;
            }
            else{
                // while(startcol > 0 && target < num){
                //     startcol--;
                // }
                startcol--;
            }
        }
        return false;
    }
};
