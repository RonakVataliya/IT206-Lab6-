class Solution {
public:
    bool solve(vector<vector<char>>& b) 
    {
        for(int i=0;i<9;i++) 
        {
            for(int j=0;j<9;j++) 
            {
                if (b[i][j]!='.') 
                { 
                    char c=b[i][j];
                    b[i][j]='.'; 
                    if (!isvalid(b, i, j, c)) 
                    {
                        return false;
                    }
                    b[i][j]=c; 
                }
            }
        }
        return true;
    }

    bool isvalid(vector<vector<char>>& b, int row, int col, char c) 
    {
        for (int i = 0; i < 9; i++) 
        {
            if (b[row][i]==c) return false; 
            if (b[i][col]==c) return false; 

            
            int startRow=(row/3)*3;
            int startCol=(col/3)*3;
            if (b[startRow+i/3][startCol+i%3]==c) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) { 
        return solve(board);
    }
};
