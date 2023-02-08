#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>> st; //height and index
        unordered_map<int, int> puddle_right_edge;
        int ans = 0;
        for(auto it=height.begin(); it<height.end(); it++){
            while(!st.empty()){
                pair<int, int> t = st.top();
                if(t.first <= *it){
                    st.pop();
                    puddle_right_edge[t.second] = it-height.begin();
                }
                else{
                    break;
                }
            }
            st.push(pair<int, int>(*it, it-height.begin()));
        }
        ans = 0;
        vector<int>::iterator current_left = height.end();
        vector<int>::iterator current_right = height.end();
        for(auto it=height.begin(); it<height.end(); it++){
            if(current_left==height.end()){
                if(puddle_right_edge.count(it-height.begin())){
                    current_left = it;
                    current_right = height.begin() + puddle_right_edge[it-height.begin()];
                }
            }
            else if(it < current_right){
                ans += *current_left - *it;
            }
            else{ //it = current_right
                if(puddle_right_edge.count(it-height.begin())){
                    current_left = it;
                    current_right = height.begin() + puddle_right_edge[it - height.begin()];
                }
                else{
                    current_left = height.end();
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    //vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> heights = { 3,2,1,1,2,4,0,4};
    cout << sol.trap(heights)<< endl;
    return 0;
}
