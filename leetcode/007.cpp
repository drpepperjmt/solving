#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool negative = false;
        if (x < 0)
        {
            negative = true;
        }
        long long inp = abs(x);
        long long ret = 0;
        while (inp > 0)
        {
            long long tmp = inp % 10;
            inp /= 10;
            ret *= 10;
            ret += tmp;
            if (ret > INT_MAX)
            {
                return 0;
            }
        }
        if (negative)
        {
            return ret * -1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int inp;
    cin >> inp;
    cout << s.reverse(inp) << endl;
}