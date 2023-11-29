
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int N = nums.size();
        int end = N - 1;
        int mid = 0, prev = 0, next = 0;

        if (N == 1)
            return 0;

        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            prev = (mid + N - 1) % N;
            next = (mid + 1) % N;

            if (nums[prev] < nums[mid] && nums[mid] > nums[next])
                return mid;
            else if (nums[prev] > nums[mid] && nums[next] < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return mid;
    }
};