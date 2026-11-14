
class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        const long long p = 31;
        const long long mod = 1e9 + 7;

        int n = a.size();
        int m = b.size();

        // Step 1: Calculate maximum repetitions
        int repeat = (m + n - 1) / n + 1;

        // Step 2: Construct repeated string
        string txt = "";

        for (int i = 0; i < repeat; i++) {
            txt += a;
        }

        int len = txt.size();

        // Step 3: Calculate p^(m-1)
        long long pPower = 1;

        for (int i = 1; i < m; i++) {
            pPower = (pPower * p) % mod;
        }

        // Step 4: Calculate initial hashes
        long long patHash = 0;
        long long winHash = 0;

        for (int i = 0; i < m; i++) {

            patHash = (patHash * p +
                       (b[i] - 'a' + 1)) % mod;

            winHash = (winHash * p +
                       (txt[i] - 'a' + 1)) % mod;
        }

        // Step 5: Rabin-Karp sliding window
        for (int i = 0; i <= len - m; i++) {

            if (patHash == winHash) {

                if (txt.substr(i, m) == b) {

                    // Minimum repetitions needed
                    return (i + m + n - 1) / n;
                }
            }

            // Calculate next window hash
            if (i < len - m) {

                long long out = txt[i] - 'a' + 1;
                long long in = txt[i + m] - 'a' + 1;

                winHash = (winHash -
                          (out * pPower) % mod + mod) % mod;

                winHash = (winHash * p) % mod;

                winHash = (winHash + in) % mod;
            }
        }

        return -1;
    }
};
