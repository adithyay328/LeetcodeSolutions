from typing import List

class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
      # Storing counts in here
      counts = {}
      for cpdomain in cpdomains:
        splitted = cpdomain.split(" ")
        count = int(splitted[0])
        domain = splitted[1]

        # Iteratively remove every period, and add to the counts
        while domain != "":
          if domain not in counts:
            counts[domain] = count
          else:
            counts[domain] += count

          # Now, remove period
          periodIndex = domain.find(".")
          if periodIndex != -1:
            domain = domain[periodIndex + 1:]
          else:
            break
      
      # Now turn counts into a list
      results = []
      for domain in counts:
        results.append(f"{counts[domain]} {domain}")
      
      return results