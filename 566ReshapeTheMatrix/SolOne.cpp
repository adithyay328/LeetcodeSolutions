class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      std::vector<std::vector<int>> result;
      
      int numElementsInOrig = mat.size() * mat[0].size();
      int numElementsInNew = r * c;
      if(numElementsInOrig != numElementsInNew) { return mat;  }
      
      int currRow = 0;
      int currColumn = 0;
      for(int i = 0; i < r; i++) {
	std::vector<int> newRow;
	for(int j = 0; j < c; j++) {
	  if(currColumn == mat[0].size()) {
	    currRow++;
	    currColumn = 0;
	  }

	  newRow.push_back(mat[currRow][currColumn]);

	  currColumn++;
	}

	result.push_back(newRow);
      }

      return result;
    }
};
