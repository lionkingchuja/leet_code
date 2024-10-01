class CustomStack {
public:
    stack<int>st;
    int len;
    int cnt;
    CustomStack(int maxSize) {
        len=maxSize;
        cnt=0;
    }
    
    void push(int x) {
        if(cnt >=len) return;
        st.push(x);
        cnt++;
    }
    
    int pop() {
        if(!st.empty()){
            int x=st.top();
            st.pop();
            cnt--;
            return x;
        }
        else return -1;
    }
    
    void increment(int k, int val) {
        if(st.empty()) return;
        vector<int>v;
        if(k >= len){
            while(!st.empty()){
                v.push_back(st.top()+val);
                st.pop();
            }
            reverse(v.begin(),v.end());
            for(auto i:v) st.push(i);
        }
        else{
            while(!st.empty()){
                v.push_back(st.top());
                st.pop();
            }
            reverse(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                if(i<k) st.push(v[i]+val);
                else st.push(v[i]);
            }
        }

        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */