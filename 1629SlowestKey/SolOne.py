class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
      currWorstTime = releaseTimes[0]
      currWorstChar = keysPressed[0]

      for i in range(1, len(releaseTimes)):
        dur = releaseTimes[i] - releaseTimes[i - 1]
        char = keysPressed[i]

        if dur > currWorstTime or ( dur == currWorstTime and char > currWorstChar ):
          currWorstTime = dur
          currWorstChar = char
      
      return currWorstChar
        
