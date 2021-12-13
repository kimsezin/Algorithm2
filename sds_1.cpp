#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int test_case;
int solution()
{
    int answer = 0;
    int N;
    cin >> N;
    vector<int> input;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);

    }
    sort(input.begin(), input.end());
    bool flag = false;
    int idx = 0;
    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (input[i] % 2 == 0)
        {
            while (1)
            {
                if (flag == true)
                {
                    flag = false;
                    if ((input[idx] + input[i]) % 2 == 0)
                    {
                        answer += input[i];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                    else
                    {
                        answer += input[idx];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }

                }
                else if (input.size() == 2)
                {
                   if ((input[idx] + input[i]) % 2 == 0)
                    {
                        answer += input[i];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                    else
                    {
                        answer += input[idx];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                }
                else if (input[idx] % 2 == 0)
                {
                    if (input[idx] == input[i])
                    {
                        if ((input[idx] + input[i]) % 2 == 0)
                        {
                            answer += input[i];
                            input.erase(input.begin() + i);
                            input.erase(input.begin() + idx);
                            idx = 0;
                            i -= 1;
                            break;
                        }
                        else
                        {
                            answer += input[idx];
                            input.erase(input.begin() + i);
                            input.erase(input.begin() + idx);
                            idx = 0;
                            i -= 1;
                            break;
                        }
                    }
                    else if ((input[idx] + input[i]) % 2 == 0)
                    {
                        answer += input[i];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                    else
                    {
                        answer += input[idx];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                }
                else
                {
                    idx++;
                    if (idx == i)
                    {
                        idx = i - 1;
                        flag = true;
                    }
                }
            }
        }

        else
        {
            while (1)
            {
                if (flag == true)
                {
                    flag = false;
                    if ((input[idx] + input[i]) % 2 == 0)
                    {
                        answer += input[i];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                    else
                    {
                        answer += input[idx];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }

                }
                else if (input.size() == 2)
                {
                    if ((input[idx] + input[i]) % 2 == 0)
                    {
                        answer += input[i];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                    else
                    {
                        answer += input[idx];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                }

                else if (input[idx] % 2 == 1)
                {
                    if (input[idx] == input[i])
                    {
                        if ((input[idx] + input[i]) % 2 == 0)
                        {
                            answer += input[i];
                            input.erase(input.begin() + i);
                            input.erase(input.begin() + idx);
                            idx = 0;
                            i -= 1;
                            break;
                        }
                        else
                        {
                            answer += input[idx];
                            input.erase(input.begin() + i);
                            input.erase(input.begin() + idx);
                            idx = 0;
                            i -= 1;
                            break;
                        }
                    }
                    else if ((input[idx] + input[i]) % 2 == 0)
                    {
                        answer += input[i];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                    else
                    {
                        answer += input[idx];
                        input.erase(input.begin() + i);
                        input.erase(input.begin() + idx);
                        idx = 0;
                        i -= 1;
                        break;
                    }
                }
           
                else
                {
                    idx++;
                    if (idx == i)
                    {
                        idx = i - 1;
                        flag = true;
                    }
                }
             
            }
        }
    }
    return answer;
}

int main() {
    
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int result = solution();
        cout << '#' << i + 1 << ' ' << result << endl;
    }
    return 0;
}