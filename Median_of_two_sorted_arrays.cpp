class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0, k = 0;
        int a = nums1.size();
        int b = nums2.size();
        int totalLength = a + b;
        
        while (i < a && j < b) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }       
        
        while (i < a) {
            res.push_back(nums1[i]);
            i++;
        }
        
        while (j < b) {
            res.push_back(nums2[j]);
            j++;
        }
 // Now, calculate the median based on the length of the merged array.
        if (totalLength % 2 == 0) {
            // If the total length is even, return the average of the two middle elements.
            int mid1 = totalLength / 2;
            int mid2 = mid1 - 1;
            return (double)(res[mid1] + res[mid2]) / 2.0;
        } else {
            // If the total length is odd, return the middle element.
            int mid = totalLength / 2;
            return (double)res[mid];
        }        
    }
};
