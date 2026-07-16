class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalGas = 0;
        int totalCost = 0;

        for (int x : gas)
            totalGas += x;

        for (int x : cost)
            totalCost += x;

        if (totalGas < totalCost)
            return -1;

        int start = 0;
        int tank = 0;

        for (int i = 0; i < gas.size(); i++) {

            tank += gas[i] - cost[i];

            if (tank < 0) {

                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};
