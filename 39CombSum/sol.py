def rSolve(candidates, target, currentSol, currSols=[]):
  """
  This function recursively solves this.

  Doesn't seem too bad; just try from
  the left to solve it, and remove previous
  candidates when moving to the right.
  """
  # First of, if the sum of currentSol is the target,
  # add to currSols and return; if it's negative
  # just return
  solSum = sum(currentSol)
  if solSum == target:
    return currSols + [currentSol]
  elif solSum > target:
    return currSols

  # Otherwise, try all future possible solutions; iterate over
  # all the candidates, add to currentSol, and recurse with
  # any candidates less than that removed
  for i, candidate in enumerate(candidates):
    # Recurse, removing smaller candidates
    # and adding the candidate to the solution
    currSols = rSolve(candidates[i:], target, currentSol + [candidate], currSols)

  return currSols
  
class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    return rSolve(candidates, target, [], [])
