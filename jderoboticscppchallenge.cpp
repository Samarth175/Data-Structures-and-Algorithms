#include <iostream>
#include <climits>
#include <cstdio>

#define MAX 10

using namespace std;

char arr[MAX][MAX];                 // to store the input
int dp[MAX][MAX];                   // to store the length of longest path possible
int r=5,c=7;                        // r - rows   c - columns    
bool vis[MAX][MAX];
pair<int,int> a[MAX][MAX];           //-- not used


int go(int i,int j){
    // if(i<0 || i>=r || j<0 || j>=c)
    //     return 0;
    if(vis[i][j])
        return 0;
    vis[i][j] = true;
    
    if(arr[i][j]=='#'){
        // vis[i][j] = false;
        return dp[i][j] = 0;
    }
    
    // cout<<i<<" "<<j<<endl;           --for testing
    
    int top = 0,bottom = 0,left = 0,right = 0;
    
    if(i>0)
        top = go(i-1,j);
        
    if(i<r-1)
        bottom = go(i+1,j);
        
    if(j>0)
        left = go(i,j-1);
        
    if(j<c-1)
        right = go(i,j+1);
        
    cout<<"i=="<<i<<" j=="<<j<<" dp->"<<dp[i][j]<<" top->"<<top<<" bottom->"<<bottom<<" left->"<<left<<" right->"<<right<<endl;
    //when all the neighbours are blocked
    if(top==bottom && top==left && top==right && top==0){
        vis[i][j] = false;
        return dp[i][j] = 1;
    }
        
    int maxVal = max(top,max(bottom,max(left,right))),maxI,maxJ;
    
    //To find the coordinates of neighbour which is contributing to longest path
    if(maxVal == top){
        maxI = i-1;
        maxJ = j;
    }else if(maxVal == bottom){
        maxI = i+1;
        maxJ = j;
    }else if(maxVal == left){
        maxI = i;
        maxJ = j-1;
    }else{
        maxI = i;
        maxJ = j+1;
    }
    a[i][j] = pair<int,int>(maxI,maxJ);          //-- not used
    vis[i][j] = false;
    return dp[i][j] = 1+maxVal;
}

int main() {
// 	int r=5,c=7;
    freopen("data.txt","r",stdin);
    freopen("data1.txt","w",stdout);
	for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        char ch;
	        cin>>ch;
	        arr[i][j] = ch;
	    }
	}

    for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        a[i][j].first = -1;
            a[i][j].second = -1;
	    }
	}
// 	go(0,2);                            --for testing  
    int answer = 0,maxI=0,maxJ=0;
	for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        // if(arr[i][j]=='#'){
	        //     vis[i][j] = true;
	        //     continue;
	        // }
            int ans = go(i,j);
            if(ans>answer){
	            answer = ans;
                maxI = i;
                maxJ = j;
            }

            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    // cout<<a[i][j].first<<","<<a[i][j].second<<" ";
                    cout<<dp[i][j]<<" ";
                    // cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
	    }
	}
    // cout<<maxI<<" "<<maxJ<<endl;


    // int count = 0;
    // while(true){
    //     cout<<maxI<<" "<<maxJ<<endl;
    //     arr[maxI][maxJ] = '0' + count;
    //     count++;
    //     if(a[maxI][maxJ].first==-1)
    //         break;
    //     int x = a[maxI][maxJ].first;
    //     int y = a[maxI][maxJ].second;
    //     maxI = x;
    //     maxJ = y;
    // }
	
	// for(int i=0;i<r;i++){
	//     for(int j=0;j<c;j++){
	//         // cout<<a[i][j].first<<","<<a[i][j].second<<" ";
    //         // cout<<dp[i][j]<<" ";
    //         // cout<<arr[i][j]<<" ";
    //         for(int i=0;i<r;i++){
    //             for(int j=0;j<c;j++){
    //                 // cout<<a[i][j].first<<","<<a[i][j].second<<" ";
    //                 cout<<dp[i][j]<<" ";
    //                 // cout<<arr[i][j]<<" ";
    //             }
    //             cout<<endl;
    //         }
    //         cout<<endl;
    //     }
	//     cout<<endl;
	// }

    // for(int i=0;i<r;i++){
	//     for(int j=0;j<c;j++){
	//         // cout<<a[i][j].first<<","<<a[i][j].second<<" ";
    //         cout<<dp[i][j]<<" ";
    //         // cout<<arr[i][j]<<" ";
    //     }
	//     cout<<endl;
	// }
	return 0;
}



//Sample Input
// ##.##.#
// #..####
// #.#####
// #..####
// #######

// Failed Test Case
// ##.##.#
// #.....#
// #.#####
// #..####
// #######

// .####.#
// ...####
// ....###
// #######
// #######