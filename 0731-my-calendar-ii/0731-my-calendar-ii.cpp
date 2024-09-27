class MyCalendarTwo {
public:
    vector<pair<int,int>>first_meet;
    vector<pair<int,int>>second_meet;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto i:second_meet){
            if(max(i.first,start) < min(i.second,end)){
                return false;
            }
        }

        for(auto i:first_meet){
            if(max(i.first,start) < min(i.second,end)){
                second_meet.push_back({max(i.first,start),min(i.second,end)});
            }
        }
        first_meet.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */