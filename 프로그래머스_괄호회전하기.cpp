#include <string>
#include <vector>
#include <stack>
using namespace std;
int answer = 0;
void check(string temp, int num)
{
    int cnt = 0;
    stack<char> s;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '{' || temp[i] == '[' || temp[i] == '(')
        {
            s.push(temp[i]);
        }
        else
        {
            if (!s.empty())
            {
                if (s.top() == '{')
                {
                    if (temp[i] == '}')
                    {
                        s.pop();
                        cnt++;
                    }
                }
                else if (s.top() == '(')
                {
                    if (temp[i] == ')')
                    {
                        s.pop();
                        cnt++;
                    }
                }
                else if (s.top() == '[')
                {
                    if (temp[i] == ']')
                    {
                        s.pop();
                        cnt++;
                    }
                }
            }
        }

    }
    if (cnt == num)
    {
        answer++;
    }
}
int solution(string s) {
    if (s.size() % 2 != 0)
    {
        return answer;
    }
    for (int i = 0; i < s.size(); i++)
    {
        s += s[0];
        s = s.substr(1);
        check(s, s.size() / 2);
    }
    return answer;
}

int main()
{
    solution("{}[]()");
    return 0;
}