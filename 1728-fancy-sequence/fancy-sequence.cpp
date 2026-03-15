class Fancy {
private:
    const long long mod = 1e9 + 7;
    long long add = 0, mul = 1;
    vector<long long> v;
    long long power(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = power(a, b / 2);
        long long res = (half * half) % mod;

        if (b % 2 == 1)
            res = (res * a) % mod;

        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        long long x = ((val - add) % mod + mod) * power(mul, mod - 2) % mod;
        v.push_back(x);
    }

    void addAll(int inc) { add = (add + inc) % mod; }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size())
            return -1;
        return (v[idx] * mul + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */