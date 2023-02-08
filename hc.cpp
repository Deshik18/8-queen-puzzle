#include <bits/stdc++.h>
#include<time.h>
using namespace std;

int N;
int board[8][8];

int checkrow(int i){
    for(int k=0;k<N;k++){
        if(board[i][k]==1){
            return 1;
        }
    }
    return 0;
}


int attack(int i,int j){
    // check columm
    for(int k=0;k<N;k++){
        if(board[k][j]==1){
            //cout << "Problem at " << k << " " << j << endl;
            return 1;
        }
    }
    int m=i;
    int n=j;
    int sl=1;
    while(m-sl>=0 && n-sl>=0){
        if(board[m-sl][n-sl]==1){
            //cout << "Problem at " << m-sl << " " << n-sl << endl;
            return 1;
        }
        sl++;
    }
    while(m+sl<N && n+sl<N){
        if(board[m+sl][n+sl]==1){
            //cout << "Problem at " << m+sl << " " << n+sl << endl;
            return 1;
        }
        sl++;
    }
    sl=-1;
    while(m+sl>=0 && n-sl<N){
        if(board[m+sl][n-sl]==1){
            //cout << "Problem at " << m+sl << " " << n-sl << endl;
            return 1;
        }
        sl--;
    }
    while(m-sl<N && n+sl>=0){
        if(board[m-sl][n+sl]==1){
            //cout << "Problem at " << m-sl << " " << n+sl << endl;
            return 1;
        }
        sl--;
    }
    return 0;
}

void hillclimb(int n){
    while(n<=N){
        vector<int> twopair;
        for(int i=0;i<N;i++){
            //cout << "Checking row i  " << i << endl;
            if(checkrow(i)==0){
                //cout << "Row i case 1 satisfied  " << i << endl;
                for(int j=0;j<N;j++){
                    //cout << "\tFor j=" << j << "  ";
                    if(attack(i,j)==0){
                        twopair.push_back(i);
                        twopair.push_back(j);
                    }
                }
                if(twopair.size()!=0){
                    int p=twopair.size()/2;
                    srand(time(0));
                    int sel=(rand())%p;
                    int xx=twopair[2*sel];
                    int yy=twopair[2*sel+1];
                    board[xx][yy]=1;
                    n++;
                    break;
                }
            }
            if(i==N-1){
                if(n==N){
                    cout << "\nSolution Found..." << endl;
                    cout << "Positions Generated:\n";
                    for(int i=0;i<N;i++){
                        for(int j=0;j<N;j++){
                            cout << board[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                else{
                    cout << "\nOops got struck... Try again" << endl;
                }
                return;
            }   
        }
    }    
}

void initialize(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=0;
        }
    }
}

int main(){
    cout << "Enter the dimension of matrix(N):\t";
    cin >> N;
    initialize();
    int n;
    cout << "Enter the number of initializations you want to enter:\t";
    cin >> n;
    cout << "Enter the coordinates of queen first row no and then column no:\n";
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        board[x-1][y-1]=1;
    }
    hillclimb(n);
}
