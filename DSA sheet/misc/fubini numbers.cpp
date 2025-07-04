class FubiniCalculator {
private:
    // Helper function to calculate binomial coefficient C(n, k)
    long long binomial(int n, int k) {
        if (k > n || k < 0) return 0;
        if (k == 0 || k == n) return 1;
        
        long long result = 1;
        for (int i = 0; i < std::min(k, n - k); i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

public:
    // Generate first n Fubini numbers using recurrence relation
    vector<long long> generateFubini(int n) {
        if (n <= 0) return {};
        vector<long long> fubini;
        fubini.push_back(1); // F(0) = 1
        for (int i = 1; i < n; i++) {
            long long nextFubini = 0;
            for (int k = 0; k < i; k++) {
                nextFubini += binomial(i - 1, k) * fubini[k];
            }
            fubini.push_back(nextFubini);
        }
        
        return fubini;
    }
};
