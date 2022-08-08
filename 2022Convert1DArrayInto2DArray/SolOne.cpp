class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
      std::vector<std::vector<int>> result;
      
      int elementsInOrig = original.size();
      int elementsInNew = m * n;

      if(elementsInOrig != elementsInNew) { return result; }

      int origIndex = 0;

      std::vector<int> newRow;
      newRow.reserve(n);
      
      for(int i = 0; i < m; i++) {
	newRow.clear();
	
	for(int j = 0; j < n; j++) {
	  newRow.push_back(original[origIndex]);
	  origIndex++;
	}

	result.push_back(newRow);
      }

      return result;
    }
};
