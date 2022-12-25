class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
      maxVal = candies[0]
      for i in range(1, len(candies)):
          maxVal = max(maxVal, candies[i])
      
      result = []
      for i in candies:
         result.append(  i + extraCandies >= maxVal  )
      
      return result