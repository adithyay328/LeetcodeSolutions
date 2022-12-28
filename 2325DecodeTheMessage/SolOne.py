import string

class Solution:
  def decodeMessage(self, key: str, message: str):
    # Build our mapping
    mapping = {}
    count = 0
    for i in key:
      if i not in mapping and i != " ":
        mapping[i] = count
        count += 1
    
    # Compute result
    result = ""
    for letter in message:
      if letter == " ":
        result += " "
      else:
        result += string.ascii_lowercase[ mapping[letter] ]
    
    return result