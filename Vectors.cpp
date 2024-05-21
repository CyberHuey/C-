// Vectors.cpp
// LeetCode: Top 150 Array problems (EASY)
// 09/13/2023

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




class VectorQuestions {
public:
    /*
        My Merge
        Time : O(n+m) due to traversing num3 size after comparing each index of nums1 + nums2
        Space: O(1) 
    */
    vector<int> merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num3;
        for(int i=0; m+n+1; i++){
            
            if (nums1[i] > nums2[i])
                num3.push_back(nums1[i]);
            else if (nums1[i] < nums2[i])
                num3.push_back(nums2[i]);
            else {
               num3.push_back(nums1[i]);
               num3.push_back(nums2[i]); 
            }
        }
		return num3;
    }
	
	// Online Solution
    vector<int> merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        return nums1;
    }
    /* Remove Element
       Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
       Then return the number of elements in nums which are not equal to val.
       Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things :
       - Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.
       - Return k. */

    int removeElement(vector<int>& nums, int val) {
        int yesval = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[yesval] = nums[i];
                yesval++;
            }
        }
        nums.erase(nums.begin() + yesval, nums.end());
        return yesval;
    }
    /*
    Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
    Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
    Return k after placing the final result in the first k slots of nums.
    Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
    */
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int i = 0;
        while (i < nums.size()) {
            int j = i;
            int count = 2;
            while (j < nums.size() && nums[i] == nums[j]) {
                if (count > 0) {
                    nums[index] = nums[i];
                    index++;
                }
                count--;
                j++;
            }
            i = j;
        }
        return index;
    }
	/* Majority Element
       Given an array nums of size n, return the majority element.
       The majority element is the element that appears more than [n / 2] times. You may assume that the majority element always exists in the array.
    */
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }

    /*
        Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

        Solution:
        Reverse array 3 times
        - reverse (end-k,end)
        - reverse (begin,end-k)
        - reverse (begin, end)
    */
    void rotate(vector<int>& nums, int k) {
        // int nums_size = nums.size();
        k = k % nums.size();
        if (k != 0)
        {
            reverse(nums.end() - k, nums.end());
            reverse(nums.begin(), nums.end() - k);
            reverse(nums.begin(), nums.end());
        }
    }
	
	/*
		Best Time to Buy and Sell Stock
		- You are given an array prices where prices[i] is the price of a given stock on the ith day.
		- You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
		- Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
	*/
	int maxProfit(vector<int>& prices) {
        int max = INT_MAX;
        int temp = 0;
        int profit = 0;
        for (int i = 0; i<prices.size(); i++){
            // Checking for lower buy value
            if (prices[i] < max){
                max = prices[i];
            }
            // Checking for higher profit
            temp = prices[i] - max;
            if (profit < temp)
                profit = temp;
        }
        return profit;
    }
	/*
		Jump Game
		- You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
		- Return true if you can reach the last index, or false otherwise.
	*/
	bool canJump(vector<int>& nums) {
        int reachable = 0;
        for( int i=0; i<nums.size(); i++){
            // If reachable is < i the canJump is False
            if(reachable < i)
                return false;
            // Update reachable if index plus nums[i] >
            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }
    /*
        Jump Game II
        - You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
        - Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
            - 0 <= j <= nums[i] and
            - i + j < n
    */
    int jump(vector<int>& nums) {
        int ans = 0;
        int end = 0;
        int farthest = 0;

        // Implicit BFS
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= nums.size() - 1) {
                ++ans;
                break;
            }
            if (i == end) {    // Visited all the items on the current level
                ++ans;           // Increment the level
                end = farthest;  // Make the queue size for the next level
            }
        }
        return ans;
    }

    /*
        Merge Strings Alternately
        You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
        If a string is longer than the other, append the additional letters onto the end of the merged string.
        Return the merged string.
    */
    string mergeAlternately(string word1, string word2) {
        string word3 = "";
        int i = 0;

        while (i < word1.size() || i < word2.size()) {
            if (i < word1.size()) {
                word3 += word1[i];
            }
            if (i < word2.size()) {
                word3 += word2[i];
            }
            i++;
        }
        return word3;
    }
    /*
        274 H-Index
        Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
        The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
    */
    int hIndex(vector<int>& c) {
        int low = 0, high = c.size();
        while (low < high) {
            int mid = (low + high + 1) / 2;
            int count = 0;
            for (int i = 0; i < c.size(); i++) {
                if (c[i] >= mid) 
                    count++;
            }
            if (count >= mid) 
                low = mid;
            else 
                high = mid - 1;
        }
        return low;
    }
};


int main (){
    //vector<int> nums1{2, 3, 1, 1, 4};
    int N1[] = { 3,2,2,3 };
	int m = 3, n=3;

    vector<int> nums2;
    nums2.assign(N1, N1 + 4);

	
    VectorQuestions S;
	
	// -vector<int> test1 = S.merge1(nums1, m, nums2, n);
    //vector<int> test2 = S.merge2(nums1, m, nums2, n);
    // -S.with_separator(test1, " ");
    //S.with_separator(test2, " ");

    //  cout << (S.removeElement(nums2, 3));

    // cout << (S.removeDuplicates(nums2));

    // S.rotate(nums1, 3);

    // cout << S.maxProfit(nums1);

    //cout << S.canJump(nums1);

    /*
        Jump II
    vector<int> nums1{2, 3, 1, 1, 4};
    cout << S.jump(nums1);
    */

    /*
    Merge Alternately
    
    string word1 = "abc";
    string word2 = "pqr";
    cout << S.mergeAlternately(word1, word2);
	*/

    /*
        H-Index
    */
    vector<int> nums1{3, 0, 6, 1, 5};
    int result = S.hIndex(nums1);
    cout << result;

}