class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
           int arr[10]={0};
           for(int j=0; j<9; j++){
            if(board[i][j]>='1' && board[i][j]<='9'){
             if(arr[board[i][j]-'0'])return false;
             else{
                arr[board[i][j]-'0']=1;
             }
            }
           }
        }
        for (int i = 0; i < 9; i++) {
           int arr[10]={0};
           for(int j=0; j<9; j++){
            if(board[j][i]>='1' && board[j][i]<='9'){
             if(arr[board[j][i]-'0'])return false;
             else{
                arr[board[j][i]-'0']=1;
             }
            }
           }
        }
        for(int i=0; i<9; i=i+3){
            for(int j=0; j<9; j=j+3){
                int y=i+3;
                int z=j+3;
                int arr[10]={0};
                for(int p=i; p<y; p++){
                    for(int q=j; q<z; q++){
                        if(board[p][q]>='1' && board[p][q]<='9'){
                        if(arr[board[p][q]-'0'])return false;
                        else{
                            arr[board[p][q]-'0']=1;
                        }
                        }
                    }
                }
            }
        }
        return true;
    }
};
