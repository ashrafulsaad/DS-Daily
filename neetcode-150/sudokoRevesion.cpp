class Solution {
	public:
		bool isValidSudoko(vector<vector<char>>& board){

			unordered_set<char> row[9];
			unordered_set<char> cols[9];
			unordered_set<char> boxs[9];

			for(int i =0;i<9;i++){

				for(int j=0; j<9;j++){
					if(board[i][j]=='.')
						continue;

					char num = board[i][j];

					int box = (i/3)*3+(j/3);

					if(rows[i].count(num))
						return false;

					if(cols[j].count(num))
						return false;

					if(boxs[box].count(num))
						return false;

					rows[i].insert(num);
					cols[j].insert(num);
					boxs[box].insert(num);	
				}
			}

		   return true;
		}
};
