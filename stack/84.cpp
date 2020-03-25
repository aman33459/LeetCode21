class Solution {
public:
    stack < pair < int , int > > span;
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int k =1;
        int in = 0;
        for(auto i : heights){
            k=0; 
           in=1;
            while(span.size() > 0 && span.top().first > i){
            //    cout << span.top().first << " " << span.top().second << " " << k << "**\n";
                ans = max(ans , (span.top().first * (span.top().second +  k)));k+=span.top().second;
                in+=span.top().second;
                span.pop();
                
            }
          //cout << i << " " << ans << " " << k << " " << in <<   " +++\n";
            span.push(make_pair(i , in));
        }
        k=0;
        while(span.size() > 0){
                
                ans = max(ans , (span.top().first * (span.top().second + k )));
            k+=span.top().second;
                span.pop();
                
            }
        
        return ans;
    }
};
