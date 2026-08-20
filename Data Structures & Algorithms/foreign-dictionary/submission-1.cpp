class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> mp;
        unordered_map<char, int> indeg;

        // Add every character to the graph
        for (string& word : words) {
            for (char c : word) {
                indeg[c] = 0;
            }
        }

        // Build edges using adjacent words
        for (int i = 1; i < words.size(); i++) {
            string& a = words[i - 1];
            string& b = words[i];

            int len = min(a.size(), b.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    // Add edge only if it doesn't already exist
                    if (!mp[a[j]].count(b[j])) {
                        mp[a[j]].insert(b[j]);
                        indeg[b[j]]++;
                    }

                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && a.size() > b.size()) {
                return "";
            }
        }

        // Kahn's algorithm
        queue<char> q;

        for (auto& [c, degree] : indeg) {
            if (degree == 0) {
                q.push(c);
            }
        }

        string ans;

        while (!q.empty()) {
            char u = q.front();
            q.pop();

            ans += u;

            for (char v : mp[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Cycle detected
        if (ans.size() != indeg.size()) {
            return "";
        }

        return ans;
    }
};