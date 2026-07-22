class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000"))
            return -1;

        queue<string> q;
        unordered_set<string> vis;

        q.push("0000");
        vis.insert("0000");

        int moves = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                string cur = q.front();
                q.pop();

                if(cur == target)
                    return moves;

                for (int i=0; i<4; i++) {

                    string up = cur;
                    string down = cur;

                    up[i] = (cur[i] == '9') ? '0' : cur[i]+1;
                    down[i] = (cur[i] == '0') ? '9' : cur[i]-1;

                    if(!dead.count(up) && !vis.count(up)) {
                        vis.insert(up);
                        q.push(up);
                    }

                    if(!dead.count(down) && !vis.count(down)) {
                        vis.insert(down);
                        q.push(down);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};