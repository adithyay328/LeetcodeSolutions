class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
      doubles = set()
      halves = set()

      for idx, val in enumerate(arr):
        if val in doubles or val in halves:
          return True
        else:
            doubles.add(val * 2)
            halves.add(val / 2)
        
      return False
