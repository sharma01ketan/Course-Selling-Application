#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    int ans = INT_MAX;
    for (int i = 0; i + m - 1 < n; ++i) {
        ans = min(ans, arr[i + m - 1] - arr[i]);
    }
    cout <<ans << "\n";
    return 0;
}