class Solution:
  def shiftingLetters(self, s: str, shifts: List[int]) -> str:
    # Maintain running sum of remaining shifts
    remainingShifts = sum(shifts)

    result = []

    for i in range(len(s)):
      # Shift s[i] so 0 is ord('a')
      currOrd = ord(s[i]) - ord('a')
      currOrd += remainingShifts
      currOrd = currOrd % (ord('z') - ord('a') + 1)
      result.append( chr( currOrd + ord('a')) )

      remainingShifts -= shifts[i]

    return "".join(result)

