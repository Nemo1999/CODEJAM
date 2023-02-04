#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        vector<string> * possible_unmatched = new vector<string>();
        possible_unmatched -> push_back(s);
        vector<string> * new_possible_unmatched = new vector<string>();
        for(auto pi = p.rbegin(); pi<p.rend(); pi++){
            bool wildcard = false;
            char matching = (*pi == '*') ? wildcard=true, *(++pi) : *pi;
            while(! possible_unmatched->empty()){
                string unmatched = possible_unmatched->back();
                possible_unmatched->pop_back();
                if(wildcard){
                    while(true){
                        string u  = unmatched;
                        new_possible_unmatched->push_back(u);
                        bool match_condition = (matching == '.') ?
                            !unmatched.empty()
                            :
                            !unmatched.empty() && unmatched.back() == matching;
                        if(match_condition)
                            unmatched.pop_back();
                        else
                            break;
                    }
                }else{
                    if(!unmatched.empty() &&
                       (unmatched.back() == matching || matching == '.')){
                        unmatched.pop_back();
                        new_possible_unmatched->push_back(unmatched);
                    }
                }
            }
            iter_swap(possible_unmatched, new_possible_unmatched);
        }
        auto it =  find_if(possible_unmatched->begin(), possible_unmatched->end(), [](string x){return x.empty();});
        return it != possible_unmatched->end();
    }
};

int main(){
    string s = "hellohello";
    string p = ".*lll.*";
    Solution sol;
    cout << s << endl;
    cout << p << endl;
    cout << sol.isMatch(s,p) << endl;
    return 0;
}
