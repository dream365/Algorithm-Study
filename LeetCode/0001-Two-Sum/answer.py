class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashTable = {}
        for i, v in enumerate(nums):
            diff = target - v
            if diff in hashTable.keys():
                return [i, hashTable[diff]]
            else:
                hashTable[v] = i
