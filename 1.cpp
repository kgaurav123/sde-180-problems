//287. Find the Duplicate Number   https://leetcode.com/problems/find-the-duplicate-number/
//Brute-Force approach O(nlogn) -time   O(1)-space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]==nums[i+1])
                return nums[i];
        return nums[0];
    }
};
//O(n)-time    O(n) -space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       vector<int> freq(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(freq[nums[i]]==1)
                return nums[i];
            freq[nums[i]]++;
        }
        return -1;
    }
};
//Linked list cycle method(Floyd's Tortoise and Hare (Cycle Detection)) Time-O(n)  space -O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
