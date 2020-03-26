class Solution {
public:
    int count[1005][1005];
    int maximalRectangle(vector<vector<char>>& matrix) {
        //cout << "amana\n";
        if(matrix.size() == 0) return 0;
        for(int i = 0 ; i <  matrix.size()  ; i++){
            int prev = 0;
            for(int j = matrix[0].size() - 1 ; j >= 0 ;j--){
                if(matrix[i][j] - '0' == 0) {
                    prev = 0;
                    count[i][j] = 0;
                }
                else{
                    prev++;
                    count[i][j]=prev;
                }
            }
        }
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << count[i][j] << " ";
            }
            cout << endl;
        }
        int ans = 0;
        
        for(int j = 0 ; j < m  ; j++){
            stack < pair < int , int > > s;
            for(int i = 0 ; i < n ; i++ ){
                int k = 0;
                while(s.size() && s.top().first > count[i][j]){
                    cout << ans << " " << count[i][j] << " " << s.top().first << " " << s.top().second << " " << k << "**\n"; 
                    ans = max(ans , s.top().first * (s.top().second + k));
                    k+=s.top().second;
                    s.pop();
                }
                s.push(make_pair(count[i][j] , k+1 ));
            }
           int  k=0;
        while(s.size()){
            ans = max(ans , s.top().first * (s.top().second + k));
            k+=s.top().second;
            s.pop();
        }
        }
        
        return ans;
    }
};
