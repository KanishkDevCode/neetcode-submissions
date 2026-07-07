class Solution {
public:
    string decodeString(string s) {
        
        stack<int> nums;
        stack<string> strs;

        string curr = "";

        int k = 0;

        for(char ch : s) {

            if(isdigit(ch)) {

                k = k*10 + (ch - '0');
            }
            else if(ch == '[') {

                nums.push(k);

                strs.push(curr);

                curr = "";

                k = 0;
            }

            else if(ch == ']') {

                int repeat = nums.top();

                nums.pop();

                string prev = strs.top();

                strs.pop();

                string temp = "";

                for(int i=0; i<repeat; i++)

                    temp += curr;
                
                curr = prev + temp;
            }

            else {
                curr += ch;
            }
        }
        return curr;
    }
};