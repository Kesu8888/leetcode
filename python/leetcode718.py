class Solution(object):
    def findLength(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
    def findLengthDP(self, dp, nums1, nums2, i, j):
        if i == len(nums1) or j == len(nums2):
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        result = 0
        if nums1[i] == nums2[j]:
            result = 1 + self.findLengthDP(dp, nums1, nums2, i + 1, j + 1)

        return 0
