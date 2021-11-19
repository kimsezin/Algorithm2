// you can use includes, for example:
// #include <algorithm>
using namespace std;
#include<map>
#include<vector>
#include<iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    map<int, int> num_cnt;
    int num = A[0];
    int num_size = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] == num)
            num_size++;
        else
        {
            num_cnt[num] = num_size;
            num = A[i];
            num_size = 1;
        }
    }
    num_cnt[num] = num_size;
    for (auto a = num_cnt.begin(); a != num_cnt.end(); a++)
    {
        cout << a->first << " " << a->second << endl;
        /*
        if(a->first - a->second > 0)
        {
            if(a->first - a->second > a->second)
                answer+=a->second;
            else
                answer+=a->first-a->second;
        }
        else
        {
            answer+=a->second-a->first;
        }
        */
    }
    return answer;
}

int main()
{
    solution({ 1,1,3,4,4,4 });
}