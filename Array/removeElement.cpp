/********************************************************************************** 
* 
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
*               
**********************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size()-1;
        
        while(left<=right)
        {
            if (nums[left] == val){
                nums[left] = nums[right];
                --right;
            }else ++left;
        }
        return (right+1);
    }
};


