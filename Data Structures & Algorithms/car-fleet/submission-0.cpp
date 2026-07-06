class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();

        vector<pair<int, double>> cars;

        for(int i=0; i<n; i++) {

            double t = (double)(target-position[i]) / speed[i];

            cars.push_back({position[i], t});
        }

        sort(cars.begin(), cars.end(), greater<>());

        stack<double> st;

        for(auto &[pos,time] : cars) {

            if(st.empty() || time > st.top()){

                st.push(time);
            }
        }
        return st.size();
    }
};
