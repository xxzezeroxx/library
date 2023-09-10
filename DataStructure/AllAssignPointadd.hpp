class AllAssignPointadd{
    //0-indexed
    // no negative number
    std::vector<long long> data;
    std::vector<int> written;
    long long base = 0;
public:
    int n;
    AllAssignPointadd(int n) : data(n,-1),n(n){}
    long long get(int idx){
        if (data[idx] == -1) return base;
        else return base + data[idx];
    }
    void assign_all(long long val){
        for (auto i: written) data[i] = -1;
        written.clear();
        base = val;
    }
    void set(int idx,long long val){
        data[idx] = val;
        written.push_back(idx); 
    }
    void add(int idx,long long val){
        if (data[idx] == -1) this->set(idx,val);
        else{
            data[idx] += val;
            written.push_back(idx);
        }
    }
};