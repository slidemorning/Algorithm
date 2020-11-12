#include <iostream>
using namespace std;

int n, m;
int arr[100000];
int segtree[100000*4];

int makeseg(int ti, int start, int end){
    if(start == end){
        segtree[ti] = arr[start];
    }else{
        int mid = (start + end) / 2;
        segtree[ti] = makeseg(ti*2 + 1, start, mid) + makeseg(ti*2 + 2, mid+1, end);
    }
    return segtree[ti];
}

int pfsum(int ti, int tl, int tr, int ps, int pe){
    if(tl > pe || tr < ps) return 0;

    if(ps <= tl && tr <= pe) return segtree[ti];

    else{
        int mid = (tl + tr) / 2;
        return pfsum(ti*2 + 1, tl, mid, ps, pe) + pfsum(ti*2 + 2, mid+1, tr, ps, pe);
    }
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    makeseg(0, 0, n-1);
    while(m--){
        int start, end;
        cin >> start >> end;
        cout << pfsum(0, 0, n-1, start-1, end-1) << '\n';
    }
}