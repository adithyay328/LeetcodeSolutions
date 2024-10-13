class Solution:
  def maximumTripletValue(self, nums: List[int]) -> int:
    maxVals = nums.copy()
    for i in range(len(nums) - 2, -1, -1):
      maxVals[i] = max(maxVals[i], maxVals[i + 1])

    # Keep the maximal value of nums[i]
    # in here. We can always reuse this
    maxI = nums[0]
    maxVal = ( nums[0] - nums[1] ) * nums[2]
  
    for j in range(1, len(nums) - 1):
      maxVal = max(maxVal, ( maxI - nums[j] ) * maxVals[j+1])
      maxI = max(maxI, nums[j])
  
    return max(maxVal, 0)
