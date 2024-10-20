class Solution {
public:
    bool parseBoolExpr(string s) {
    stack<char> st1;  
    stack<char> st2;  
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '&' || s[i] == '|' || s[i] == '!') {
            st1.push(s[i]);  
        }
        else if (s[i] == '(') {
            st2.push(s[i]);  
        }
        else if (s[i] == ')') {
           
            char op = st1.top();
            st1.pop();
            vector<char> vals;
            
            // Collect all values between '(' and ')'
            while (st2.top() != '(') {
                vals.push_back(st2.top());
                st2.pop();
            }
            st2.pop();  // Pop the '('
            
            // Perform the operation based on the operator
            char result = 't';
            if (op == '&') {
                result = 't';
                for (char c : vals) {
                    if (c == 'f') {
                        result = 'f';
                        break;
                    }
                }
            } 
            else if (op == '|') {
                result = 'f';
                for (char c : vals) {
                    if (c == 't') {
                        result = 't';
                        break;
                    }
                }
            } 
            else if (op == '!') {
                result = (vals[0] == 't') ? 'f' : 't';
            }
            st2.push(result);
        } 
        else {
            st2.push(s[i]); 
        }
    }
    return st2.top() == 't'; // converting in to bool
}

};