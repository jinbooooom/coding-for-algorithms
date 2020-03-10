/*
牛客网输入输出练习：https://ac.nowcoder.com/acm/contest/320#question
*/

/*
计算a+b，输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据包括多组。输出a+b的结果
输入
1 5
10 20

输出
6
30
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int a, b;
    while(cin >> a >> b)
        cout << a + b << endl;
}

/*
计算a+b，输入第一行包括一个数据组数t(1 <= t <= 100)，接下来每行包括两个正整数a,b(1 <= a, b <= 10^9)，输出a+b的结果
输入
2
1 5
10 20
输出
6
30
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int t;
    while(cin >> t)
    {
        while(t--)
        {
            int a, b;
            cin >> a >> b;
            cout << a + b << endl;
        }
    }
}

/*
计算a+b，输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 输出a+b的结果。如果输入为0 0则结束输入。
输入
1 5
10 20
0 0
输出
6
30
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int a, b;
    while(cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        cout << a + b << endl;
    }
}

/*
计算一系列数的和，输入数据包括多组。，每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。输出每组数据输出求和的结果。
输入
4 1 2 3 4
5 1 2 3 4 5
0
输出
10
15
*/
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    int n, res;
    while(1)
    {
        cin >> n;
        if (n == 0)
            break;
        res = 0;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        for (int i = 0; i < n; ++i)
            res += vec[i];
        cout << res << endl;
    }
}

/*
计算一系列数的和
输入描述:
输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
接下来t行, 每行一组数据。
每行的第一个整数为整数的个数n(1 <= n <= 100)。
接下来n个正整数, 即需要求和的每个正整数。
输出描述:
每组数据输出求和的结果

输入
2
4 1 2 3 4
5 1 2 3 4 5
输出
10
15
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int t, n, res = 0;
    int num;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        res = 0;
        for (int j = 0; j < n; ++j)
        {
            cin >> num;
            res += num;
        }
        cout << res << endl;
        res = 0;
    }
}

/*str(1)
对输入的字符串进行排序后输出
输入描述:
输入有两行，第一行n
第二行是n个空格隔开的字符串
输出描述:
输出一行排序后的字符串，空格隔开，无结尾空格
输入：
5
c d a bb e
输出：
a bb c d e
*/
// C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubble(vector<string>& vec)
{
    int len = vec.size();
    for (int i = 0; i < len - 1; ++i)
        for (int j = 0; j < len - i - 1; ++j)
            if (vec[j] > vec[j + 1])
            {
                string t = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = t;
            }
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    bubble(vec);
    for (int j = 0; j < n; ++j)
        cout << vec[j] << " ";
}

# Python
while True:
    try:
        n = int(input().strip().strip())
        strs = input().strip().split()
        strs.sort()
        print(' '.join(strs))
    except:
        break

/*str(2)
对输入的字符串进行排序后输出
输入描述:
多个测试用例，每个测试用例一行。
每行通过空格隔开，有n个字符，n＜100
输出描述:
对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开

输入
a c bb
f dddd
nowcoder

输出
a bb c
dddd f
nowcoder
*/

// C++
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string tmp;
    vector<string> v;
    /* cin 会把一行字符串按照空格自动分成多个字符
    比如 "abc def  jj      ok" 会打印成
    abc
    def
    jj
    ok
    */
    while(cin >> tmp) {
        v.push_back(tmp);
        if(cin.get() == '\n') {
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            v.clear();
        }
    }
    return 0;
}

# Python
while True:
    try:
        strs = input().strip().split()
        strs.sort()
        print(' '.join(strs))
    except:
        break

/*str(3)
对输入的字符串进行排序后输出
输入描述:
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输出描述:
对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格

输入
a,c,bb
f,dddd
nowcoder

输出
a,bb,c
dddd,f
nowcoder
*/

// C++
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    vector<string> v;
    string str;
    while(cin >> str) {
        string s = "";
        for (int i = 0; i < str.size(); i++){
            if (str[i] != ','){
                s +=str[i];
            }
            else{
                v.push_back(s);
                s = "";
            }
            if (i == str.size()-1)
                v.push_back(s);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << ',';
        }
        cout << v[v.size() - 1] << endl;
        v.clear();
    }
    return 0;
}

# Python
while True:
    try:
        strs = input().strip().split(',')
        strs.sort()
        print(','.join(strs))
    except:
        break