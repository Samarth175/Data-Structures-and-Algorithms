#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 100005
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
	    int n,p,a[MAX],b[MAX];
	    cin>>n>>p;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    sort(a,a+n);
	    b[0] = 0;
	    for(int i=1;i<n;i++)
	        b[i] = (i*(a[i]-a[i-1]))+b[i-1];
	    int ans = INT_MAX;
	    for(int j=p-1;j<n;j++){
	        int k=j-p+1;
	        int val = b[j] - b[k] - (k*(a[j]-a[k]));
	        ans = min(ans,val);
	    }
	    cout<<"Case #"<<z<<": "<<ans<<endl;
	}
	return 0;
}


// Sample Test Case
// 3
// 4 3
// 3 1 9 100
// 6 2
// 5 5 1 2 3 4
// 5 5
// 7 7 1 7 7