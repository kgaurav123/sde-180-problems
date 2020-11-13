//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
//Find missing and repeating number
//Time-O(n)   space - O(n)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        vector<int> freq(n,0);
        for(int i=0;i<n;i++)
        freq[arr[i]-1]++;
        int rep=0,mis=0;
        int *a=new int[2];
        for(int i=0;i<n;i++)
        {
            if(freq[i]==2)
            a[0]=i+1;
            else if(freq[i]==0)
            a[1]=i+1;
        }
        return a;
    }
};
// for small integers but will fail for int in large integers cases,better use long long or cpp_int
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int sl=n*(n+1)/2;
        int sd=n*(n+1)*(n*2+1)/6;
        int s=0,s1=0;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            s1+=(arr[i]*arr[i]);
        }
        int a=sl-s,b=sd-s1;
        int su=b/a;
        int *p=new int[2];
        p[1]=(a+su)/2;
        p[0]=p[1]-a;
    }
};

//Efficient approach(XOR method)

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xor1=arr[0];
        for(int i=1;i<n;i++)
        xor1=xor1^arr[i];
     
        for(int i=1;i<=n;i++)
        xor1=xor1^i;
        int c=xor1&(~(xor1-1));
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&c)
            a^=arr[i];
            else
            b^=arr[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(i&c)
            a^=i;
            else
            b^=i;
        }
        int *p=new int[2];
        p[0]=a;
        p[1]=b;
        return p;
        
        
        
    }
};
