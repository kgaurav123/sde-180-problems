//https://leetcode.com/problems/sort-colors/
//75. Sort Colors  Time-O(nlogn)   Space-O(1)   
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

//Time-O(n)+O(n)   Space-O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o=0,z=0,t=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                z++;
            else if(nums[i]==1)
                o++;
            else
                t++;
        }
        for(int i=0;i<z;i++)
            nums[i]=0;
        for(int i=z;i<z+o;i++)
            nums[i]=1;
        for(int i=z+o;i<z+o+t;i++)
            nums[i]=2;
        
        
    }
};

//Time-O(n)(one pass)   space-O(1)  Dutch National Flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0,mid=0;
        int hi=nums.size()-1;
        while(mid<=hi)
        {
            if(nums[mid]==0)
                swap(nums[lo++],nums[mid++]);
            else if(nums[mid]==1)
                mid++;
            else
                swap(nums[mid],nums[hi--]);
        }
    }
};
