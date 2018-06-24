#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>

using namespace std;

int a[10001];

//hole 洞的编号; m 有几个洞;n 总的天数;
bool check(int hole, int m, int n)
{
	if (hole == a[1]) return true;
	stack<int> st1;
	st1.push(hole);
	//第几天
	int j = 1;
	while (j <= n) {
        //hole = st1.top();
        //cout << "hole:" << hole << endl;
		if (hole == a[j]) {
			if (hole-2 <= 1 || hole+2 >= m) { j--; break; }
			else {
				st1.pop();
				hole = st1.top();
				j++;
				if (hole == 1)
					hole++;
				else
					hole--;
				st1.push(hole);
			}
		} else {
            if (hole > m) {
                if (hole - 2 == a[j]) {j--; break;}
                else {
                    st1.pop();
                    st1.push(hole-2);
                    hole -= 2;
                    j++;
                }
            } else if (hole < 1) {
                if (hole + 2 == a[j]) {j--; break;}
                else {
                    st1.pop();
                    st1.push(hole+2);
                    hole += 2;
                    j++;
                }
            } else {
                hole++;
                j++;
                st1.push(hole);
            }
        }
	}
    //cout << "j" << j << endl;
    return j <= n ? true : false;
}

int main()
{
	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int index = 0;
	for (int i = 1; i <= m; i++) {
		if(check(i, m, n)) {
			index++;
		}
	}
	if(index == m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
