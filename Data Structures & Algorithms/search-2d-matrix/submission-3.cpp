class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int start=0;
        int end=n-1;
        int row=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[mid][0]>target){
              end=mid-1;
            }else if(matrix[mid][m-1]<target){
                start=mid+1;
            }else if(matrix[mid][0]<=target && target<=matrix[mid][m-1]){
                row=mid;
                break;
            }
        }
        if(row==-1)return false;
        cout<<row<<endl;
        start=0;
        end=m-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid]>target){
                end=mid-1;
            }else if(matrix[row][mid]<target){
                start=mid+1;
            }
        }
        return false;
    }
};
