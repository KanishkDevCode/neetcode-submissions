#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> parent;

    // Find root representative with path compression
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    // Union two components
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        unordered_map<string, int> emailToAcc;

        // Step 1: Map emails to account indices & union connected accounts
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToAcc.count(email)) {
                    unite(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        // Step 2: Group unique emails under their ultimate root account index
        unordered_map<int, vector<string>> mergedEmails;
        for (auto& [email, accIdx] : emailToAcc) {
            int rootAcc = find(accIdx);
            mergedEmails[rootAcc].push_back(email);
        }

        // Step 3: Build formatted output with sorted emails
        vector<vector<string>> result;
        for (auto& [rootAcc, emails] : mergedEmails) {
            sort(emails.begin(), emails.end()); // Requirement: sorted emails
            
            vector<string> account;
            account.push_back(accounts[rootAcc][0]); // Name
            account.insert(account.end(), emails.begin(), emails.end());
            
            result.push_back(account);
        }

        return result;
    }
};