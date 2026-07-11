class Solution {
public:

    int binarySearchAsc(MountainArray &arr, 
                        int left,
                        int right,
                        int target)
    {
        while(left<=right) 
        {
            int mid = left + (right - left) / 2;

            int val = arr.get(mid);

            if(val == target)
                return mid;

            if(val < target)
                left = mid + 1;

            else
                right = mid - 1;
        }

        return -1;
    }

    int binarySearchDesc(MountainArray &arr,
                         int left,
                         int right,
                         int target)
    {
        while(left<=right)
        {
            int mid = left + (right-left) / 2;

            int val = arr.get(mid);

            if(val == target)
                return mid;

            if(val < target)
                right = mid - 1;

            else
                left = mid + 1;
        }

        return -1; 
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();

        int left = 0;
        int right = n-1;

        while (left < right)
        {
            int mid = left + (right-left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid+1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        int peak = left;

        int ans = binarySearchAsc(mountainArr, 0, peak, target);

        if (ans!=-1)
            return ans;

        return binarySearchDesc(mountainArr, peak+1, n-1, target);
    }
};