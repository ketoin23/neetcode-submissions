class KthLargest {
    priority_queue<int, vector<int>, greater<int>> q;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto i : nums) {
            q.push(i);
            if(q.size() > k)
                q.pop();
        }

        kk = k;
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > kk) {
            q.pop();
        }

        return q.top();
    }
};
