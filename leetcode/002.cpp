#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *cur = ans;
        bool round = false;
        while (l1 || l2)
        {
            int digit = (round ? 1 : 0);
            if (l1 && !l2)
            {
                digit += l1->val;
                l1 = l1->next;
            }
            else if (!l1 && l2)
            {
                digit += l2->val;
                l2 = l2->next;
            }
            else
            {
                digit += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            if (digit >= 10)
            {
                digit -= 10;
                round = true;
            }
            else
            {
                round = false;
            }

            ListNode *tail = new ListNode(digit);
            if (!ans->next)
            {
                ans->next = tail;
            }
            else
            {
                cur->next = tail;
            }
            cur = cur->next;
        }

        if (round)
        {
            cur->next = new ListNode(1);
        }

        return ans->next;
    }
};

int main()
{
    Solution s;
    ListNode *a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    ListNode *b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);

    ListNode *ans = s.addTwoNumbers(a, b);
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}