class Solution:
    def minOperations(self, s: str) -> int:
      zeroCount = 0
      oneCount = 0

      for idx, val in enumerate(s):
        # Cases where we need to increment zero count
        if idx % 2 == 0 and val != "0":
            zeroCount += 1
        elif idx > 0 and idx % 2 == 1 and val != "1":
            zeroCount += 1
        
        if idx % 2 == 0 and val != "1":
            oneCount += 1
        elif idx > 0 and idx % 2 == 1 and val != "0":
            oneCount += 1
      
      return min(zeroCount, oneCount)
