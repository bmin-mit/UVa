#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), (void)cin.tie()
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

template <class T, class V>
ostream &operator<<(ostream &o, pair<T, V> p);

#define P(T, O, C)                          \
    template <class U>                      \
    ostream &operator<<(ostream &o, T<U> v) \
    {                                       \
        o << O;                             \
        int f = 0;                          \
        for (auto &i : v)                   \
            o << (f++ ? ", " : "") << i;    \
        return o << C;                      \
    }

#define Q(T, O, C)                             \
    template <class K, class V>                \
    ostream &operator<<(ostream &o, T<K, V> v) \
    {                                          \
        o << O;                                \
        int f = 0;                             \
        for (auto &i : v)                      \
            o << (f++ ? ", " : "") << i;       \
        return o << C;                         \
    }

P(vector, '[', ']')
P(set, '{', '}')
Q(map, '{', '}')

template <class T, class V>
ostream &operator<<(ostream &o, pair<T, V> p)
{
    return o << "(" << p.first << ", " << p.second << ")";
}

template <class T, size_t N>
ostream &operator<<(ostream &o, array<T, N> v)
{
    o << "[";
    int f = 0;
    for (auto &i : v)
        o << (f++ ? ", " : "") << i;
    return o << "]";
}

void dbg(const char *s) { cerr << endl; }

template <class T, class... A>
void dbg(const char *s, T v, A... a)
{
    const char *c = s;
    int b = 0;
    while (*c && (*c != ',' || b))
        b += bool(strchr("({[", *c)), b -= bool(strchr(")}]", *c)), c++;
    cerr.write(s, c - s) << " = " << v << (sizeof...(a) ? " |" : "");
    if (sizeof...(a))
        dbg(c + 1, a...);
    else
        cerr << endl;
}

#ifdef LOCAL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

int n, m;
vector<int> arr;
int target, maxLow = 0, minUp = INT_MAX;

void back(int i = 0, int curr = 1, int len = 0)
{
    if (len == 4)
    {
        int lower = target - target % curr;
        int upper = (target + curr - 1) / curr * curr;

        maxLow = max(lower, maxLow);
        minUp = min(upper, minUp);

        debug(i, curr, len, lower, upper);

        return;
    }

    if (i >= n)
        return;

    back(i + 1, lcm(curr, arr[i]), len + 1);
    back(i + 1, curr, len);
}

void solve()
{
    while (m--)
    {
        cin >> target;
        maxLow = 0, minUp = INT_MAX;

        back();

        cout << maxLow << ' ' << minUp << endl;
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    while (true)
    {
        cin >> n >> m;
        if (!(n + m))
            break;

        arr.resize(n);
        for (auto &elem : arr)
            cin >> elem;

        solve();
    }

    return 0;
}
