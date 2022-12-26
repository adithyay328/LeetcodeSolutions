class Solution:
  def findRelativeRanks(self, score):
    # Construct a new array that stores a list of
    # tuples [ (score, indx) ]. Then we can iterate through
    # and easily construct our solution list
    tupleList = [ (scoreVal, idx) for idx, scoreVal in enumerate(score) ]
    tupleList.sort(key = lambda x: x[0])

    # Now, iterate over the sorted tuple list, which is now ascending,
    # and write our results into the original array
    for idx, tupe in enumerate(tupleList):
      # Unpack tuple
      scoreVal, origIdx = tupe

      stringToWrite = ""
      # Figure out what string to write into score
      if idx == len(score) - 1:
        stringToWrite = "Gold Medal"
      elif idx == len(score) - 2:
        stringToWrite = "Silver Medal"
      elif idx == len(score) - 3:
        stringToWrite = "Bronze Medal"
      else:
        stringToWrite = str(len(score) - idx)
      
      # Write into the correct index
      score[origIdx] = stringToWrite

    return score