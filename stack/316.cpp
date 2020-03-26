class Solution {
public:
    stack < char > st;
    map < char , int > visited;
    string ans="";
    map < char , int > count;
    string removeDuplicateLetters(string s) {
        for(auto i : s) count[i]++;
        for(auto i : s){
            
            count[i]--;
            if(visited[i]) continue;
            while(st.size() > 0  && st.top() > i && count[st.top()] !=0){
                cout << st.top() << " " << count[i] << "**\n";
                visited[st.top()] = 0;
                st.pop();
            }
            st.push(i);
            visited[i] = 1;
        }
        while(st.size()){
            ans=st.top()+ans;
            st.pop();
        }
        //ans = ans + res;
        return ans;
    }
};
