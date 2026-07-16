class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        int farthestChecked = 1;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthestChecked);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {

                if (s[j] == '0') {

                    if (j == n - 1)
                        return true;

                    q.push(j);
                }
            }

            farthestChecked = end + 1;
        }

        return n == 1;
    }
};