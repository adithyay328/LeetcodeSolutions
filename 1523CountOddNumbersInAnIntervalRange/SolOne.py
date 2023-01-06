class Solution:
    def countOdds(self, low: int, high: int) -> int:
      count = 0
      # We're going to squeeze the low and high together
      # with both endpoints being even, and then we can just
      # compute it algebraicly
      if low % 2 == 1:
        count += 1
        low += 1
      if high % 2 == 1:
        if low < high:
          # One edge case is if both low and high are the same
          count += 1
        high -= 1
      
      if low < high:
        # Compute the remainder of the numbers
        count += (high - low) / 2
      
      return int(count)