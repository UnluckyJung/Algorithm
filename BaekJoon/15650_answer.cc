#include<bits/stdc++.h>
using namespace std;

//15650 N과 M (2)
int n, m;

int a[10];
void go(int index, int selected){
    if(selected == m){
        for(int i = 0; i<m; ++i)  cout << a[i] << " ";
        cout <<"\n";
        return;
    }

    if(index > n)   return;
    a[selected] = index;
    go(index + 1, selected + 1);
    a[selected] = 0;    //없어도 되지 않나?
    go(index +1 , selected);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >>m;
    go(1, 0);
	return 0;
}