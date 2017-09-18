// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : ljin029
// Date   : 2017-09-18

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*               
**********************************************************************************/

/*
* Reference: https://www.youtube.com/watch?v=81Pi4lAbkns
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m>n) return findMedianSortedArrays(nums2,nums1);
        if (m==0) return (nums2[(n-1)/2]+nums2[n/2])/2.0;
            
        int left=0, right=m;
        int half = (n+m+1)/2;
        int i,j,maxLeft,minRight;
        while (left<=right)
        {
            i = (left+right)/2;
            j = half - i;
            if (i<m && nums1[i]<nums2[j-1])
                left=i+1;
            else if (i>0 && nums1[i-1]>nums2[j])
                right=i-1;
            else{
                if(i==0) maxLeft = nums2[j-1];
                else if (j==0) maxLeft=nums1[i-1];
                else maxLeft=max(nums1[i-1],nums2[j-1]);
                    
                if(i==m) minRight=nums2[j];
                else if (j==n) minRight=nums1[i];
                else minRight=min(nums1[i], nums2[j]);
                
                if ((m+n)%2==0) return (maxLeft+minRight)/2.0;
                else return maxLeft;
            }
        }

    }
};


