#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = words[0].size();

// init state
        vector<unordered_map<string, int>> cs;
        vector<list<string>> qs;
        for(int i=0;i<l;i++) cs.push_back(unordered_map<string, int>());
        for(int i=0;i<l;i++) qs.push_back(list<string>());

// record word frequencies
        unordered_map<string, int> counter;
        int total = 0;
        for(const string& w: words){
            if(counter.count(w)){
                counter[w] += 1;
                total++;
            }
            else{
                for(auto& c : cs) c[w]=0;
                counter[w]=1;
                total++;
            }
        }
// solve
        vector<int> ans;
        for(auto it=s.begin(); it<s.end()-l+1; ++it){
            string substr(it, it+l);
            int index = (it - s.begin());
            auto& c = cs[index % l];
            auto& q = qs[index % l];
            if(! counter.count(substr)){
                while(q.size()){
                    c[q.front()] -= 1;
                    q.pop_front();
                }
            }else{
                if(c[substr] < counter[substr]){
                    c[substr]++;
                    q.push_back(substr);
                    if(q.size() == total)
                        ans.push_back(index - (total-1) * l);
                }else if(q.size() == total && q.front() == substr){
                    q.pop_front();
                    q.push_back(substr);
                    ans.push_back(index - (total-1) * l);
                }else{
                    q.push_back(substr);
                    while(q.front()!=substr){
                        c[q.front()]--;
                        q.pop_front();
                    }
                    q.pop_front();
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    string s("barfoothefoobarman");
    cout << s << endl <<endl<<endl;
    vector<string> words = {"foo", "bar"};
    vector<int> answer = sol.findSubstring(s, words);
    cout<< "{";
    for(int a: answer){
        cout<<" "<<a;
    }
    cout<<" }"<<endl;
    return 0;

}
