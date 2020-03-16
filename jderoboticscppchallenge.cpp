// Method 1 (verified)

#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define r 20
#define c 20

int dp[r][c]={0,0};
int max1=-1;
 int wasMax = 1;
int newArr[r][c]={0,0};
int maxI=0, maxJ=0;
int currMax = 0;
int lastWrite = 9999999;      //idhar max int dalna
pair<int,int> p[r][c]; 

bool safe(int x, int y){
   if (x < r && y < c && x >= 0 && y >= 0)
		return true;
  return false;
}

bool valid(int m[r][c], int v[r][c], int x, int y){

    if(m[x][y]==1 || v[x][y])
         return false;
    return true;
}

int path(int m[r][c],int v[r][c],int i, int j,int count){

   
      if( max1 < count ){
        max1 = count;
        wasMax = 1;
        lastWrite = 99999999;
        for(int i1=0;i1<r;i1++){
          for(int j1=0;j1<c;j1++){
                  newArr[i1][j1] = 0;              
          } 
        // cout<<"\n";    

        }
        
        cout<<"resetting for max = "<<max1<<endl;
      }


      v[i][j]=1;

      if(safe(i+1,j) && valid(m,v,i+1,j)) 
        {
        path(m,v,i+1,j,count+1); 
        v[i+1][j] = 0;
        }
      if(safe(i,j+1) && valid(m,v,i,j+1))
        {path(m,v,i,j+1,count+1);
        v[i][j+1] = 0;}
      if(safe(i-1,j) && valid(m,v,i-1,j))
        {path(m,v,i-1,j,count+1);
        v[i-1][j] = 0;}
      if(safe(i,j-1) && valid(m,v,i,j-1))
         {path(m,v,i,j-1,count+1);  
         v[i][j-1] = 0;}
    

    if(wasMax && lastWrite > count)
       {
        cout<<"Writing for max "<<max1<<" with count "<<count<<endl;
         lastWrite = count;
        newArr[i][j]=count;
       }

    if(count == 1)
    {
      wasMax = 0;
      lastWrite = 9999999;
    }
    // max(count,dp[i][j]) ;

}


int main(){

int visit[r][c];
freopen("data.txt","w",stdout);
memset(visit,0,sizeof visit);
memset(dp,0,sizeof dp);
// int l,max1=-1;

int l;
int result=0;
int m[r][c]={
  
          // {  0, 1, 1, 1, 1, 1, 1 }, 
					// {  0, 0, 0, 1, 1, 1, 1 }, 
					// {  0, 0, 0, 0, 1, 1, 1 },
          // {  1, 1, 1, 1, 1, 1, 1 },
          // {  1, 1, 1, 1, 1, 1, 1 }
        
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1}
        
        };

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(m[i][j]==0)
                   { l=path(m,visit,i,j,1);
                       visit[i][j] = 0;
                    }
                    //  if(l>max1){
                    //    max1=l;
                    //    cout<<"i=="<<i<<" "<<"j=="<<j;
                    //  }
                    // cout<<"\n";               
            }
                    // cout<<"\n";

        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // cout<<newArr[i][j]<<"\t";
                  //  cout<<p[i][j].first<<","<<p[i][j].second<<" ";

                  cout<<newArr[i][j]<<"\t";
               
        }
        cout<<"\n";    
        }
cout<<"\n\n\n";


cout<<"MAX is "<<max1<<endl<<endl;

        // cout<<result<<"\n";
}


    // if(safe(i+1,j) && valid(m,v,i+1,j)) 
    //     path(m,v,i+1,j,count+1); 
    //   if(safe(i,j+1) && valid(m,v,i,j+1))
    //     path(m,v,i,j+1,count+1);
    //   if(safe(i-1,j) && valid(m,v,i-1,j))
    //       path(m,v,i-1,j,count+1);
    //   if(safe(i,j-1) && valid(m,v,i,j-1))
    //      path(m,v,i,j-1,count+1);         
  
      // if(max1<count){
      //   max1 = count;
      //   wasMax = 1;
      //   cout<<"MAX "<<max1<<endl;
        
      //   for(int i2=0;i2<r;i2++)
      //   {
      //     for(int j2=0 ; j2<c;j2++)
      //     {
      //       dp[i2][j2]=0;
      //     }
      //   }

      // }

        //    for(int i1=0;i1<r;i1++){
        //     for(int j1=0;j1<c;j1++){
        //         cout<<v[i1][j1]<<" ";
        //           //  cout<<p[i][j].first<<","<<p[i][j].second<<" ";
            
        // }
        // cout<<"\n";    
        // }
        // cout<<"count "<<count;
        // cout<<"\n\n";


        //   {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,0, 1, 1, 1, 1, 1},
        // {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1}












//Method 2 (@todo code to be rectified for failed test cases)

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