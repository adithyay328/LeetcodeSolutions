class Solution:
    def maxArea(self, height):
      start = 0
      end = len(height) - 1
      value = lambda start, end: min(height[start], height[end]) * (abs(start - end))
      maxVal = 0

      while start < end:
        maxVal = max(maxVal, value(start, end))
        if height[start] <= height[end]:
          start += 1
        else:
          end -= 1

      return maxVal