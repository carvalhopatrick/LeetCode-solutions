// # https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/
// # Find Peak Element

int findPeakElement(int* nums, int numsSize){
    int l = 0;
    int r = numsSize/2;
	int c = 0;

    while (l < r) {
        c = l + (r-l)/2;

        if (nums[c] < nums[c+1]) {
            l = c+1;
        }
        else r = c;
    }
    return left;
}