#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<map>
#include<queue>
#include<functional>

using namespace std;

template<typename P> struct cmp_snd{
    bool operator()(const P &p1, const P &p2){
        return p1.second < p2.second;
    }
};




    int main(){
    int N;
    cin >> N; // number of fuel stops
    map<int, int> gas_stops;
    // each gas_stops contains 2 fields:
    // 1. dist to town of the fuel stops
    // 2. units of fuel in those fuel stops
    for(int i=0;i<N;i++){
        int dist, fuel;
        cin >> dist >> fuel;
        gas_stops[dist] = fuel;
    }
    int L, P; // current dist to town and current units of fuel
    cin >> L >> P;

    // return
    // 1. minimum number of stops needed to reach the town
    // 2. return -1 it is impossible to reach the town




    // function<bool (pair<int, int>, pair<int,int>)>  less_f =
    //     [](pair<int,int> p1, pair<int,int> p2 ){return p1.second < p2.second;};
    // cout<< "less_test: " << less_f(make_pair(2,2), make_pair(1,3)) <<endl;

    // priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(less_f)> fuel_pq;
    typedef  pair<int,int> fuel_stop;
    priority_queue<fuel_stop, vector<fuel_stop>, cmp_snd<fuel_stop> > fuel_pq;
    int cnt = 0;
    for(auto it = gas_stops.rbegin(); it != gas_stops.rend();++it){
        const auto d_f = *it;
        // move to the next fuel stop
        P -= L - d_f.first;
        L = d_f.first;
        while(P < 0){
            // if we are out of fuel, we choose the maxmal stop in current avail list
            if(fuel_pq.empty()){
                cnt =-1 ;
                break;
            }
            fuel_stop use_stop = fuel_pq.top(); fuel_pq.pop();
            P += use_stop.second;
            cnt++;
        }
        // add
        fuel_pq.push(d_f);
    }
    cout << cnt  <<endl;
}
