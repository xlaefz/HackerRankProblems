class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j = nums.size()-1;
        int i= 0;
        sort(nums.begin(), nums.end());
        vector<int> result;
        
        
        while(true){
            if(nums[i]+nums[j] < target){
                i++;
            }else if(nums[i] + nums[j] > target){
                j--;
            }else if (nums[i] + nums[j] == target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
        return result;
    }
};