class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        def f(i,j):
            if i == j:
                return nums[i]

            l = nums[i] - f(i+1, j)
            r = nums[j] - f(i, j-1)

            return max(l,r)

        return f(0, len(nums) - 1) >= 0            
        