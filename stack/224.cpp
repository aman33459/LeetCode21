class Solution {
public:
    stack < pair < int , int >  > st;
    int calculate(string s) {
        int eval = 0;
        int k = 0 ;
        int ans=0;
        for(auto i : s){
           // cout << i << " " << ans << "***\n";
            if(i == '('){
                st.push(make_pair(-1 , -5));
            }
            else if(i >= '0' && i <= '9'){
                ans = ans * 10 + (i-'0');
            }
            else if( i == '+'){
                eval = 1;
                if(st.size() && st.top().second!=-5) {
                    if(st.top().second == 1) ans+=st.top().first;
                    else ans=st.top().first - ans;
                    st.pop();
                }
                st.push(make_pair(ans , eval));
                ans = 0;
                k=0;
            }
            else if(i == '-'){
                eval = -1;
                if(st.size() && st.top().second!=-5) {
                    if(st.top().second == 1) ans+=st.top().first;
                    else ans=st.top().first - ans;
                    st.pop();
                }
                
                st.push(make_pair(ans , eval));
                ans = 0;
                k=0;
            }
            else if( i == ')'){
                while(st.size() && st.top().second!=-5){
                    if(st.top().second == 1) ans+=st.top().first;
                    else ans=st.top().first - ans;
                    st.pop();
                }
                st.pop();
            }
            else{
                continue;
            }
            //if(st.size())cout << st.top().first << " " << st.top().second  << "\n";
            
        }
       // ans = 0;
       // cout << ans << "**\n";
        while(st.size()){
            if(st.top().second == 1) ans+=st.top().first;
            else ans=st.top().first-ans;
            st.pop();
        }
        return ans;
    }
};
