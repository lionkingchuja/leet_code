class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());
        int index = 0;

        while (index < n) {
            char ch = formula[index];
            if (ch == '(') {
                stack.push(unordered_map<string, int>());
                index++;
            } else if (ch == ')') {
                unordered_map<string, int> curMap = stack.top();
                stack.pop();
                index++; // Move to the next character
                // Find the multiplier
                string multiplier;
                while (index < n && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                // Multiply the count - ()n
                if (!multiplier.empty()) {
                    int m = stoi(multiplier);
                    for (auto &pair : curMap) {
                        pair.second *= m;
                    }
                }
                // Insert popped map elements into stack top
                for (auto &pair : curMap) {
                    stack.top()[pair.first] += pair.second;
                }
            } else { // Atom name and count
                // Take the uppercase letter
                string atomName(1, ch);
                index++;
                // Collect all lowercase letters
                while (index < n && islower(formula[index])) {
                    atomName += formula[index];
                    index++;
                }
                string count;
                while (index < n && isdigit(formula[index])) {
                    count += formula[index];
                    index++;
                }
                int c = !count.empty() ? stoi(count) : 1;
                stack.top()[atomName] += c;
            }
        }
        
        // Sort and build the result
        map<string, int> sortedMap(stack.top().begin(), stack.top().end());
        string result;
        for (const auto &pair : sortedMap) {
            result += pair.first;
            if (pair.second > 1) {
                result += to_string(pair.second);
            }
        }
        return result;

    }
};