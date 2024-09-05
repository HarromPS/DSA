#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m = 4, n = 5;
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<n;j++){
    //         if((j>=i) && (j<n-i)){
    //             printf("+ ");
    //         }

    //     }
    //     printf("\n");
    // }

    n=5*2;
    for(int i=0;i<n;i++){
        if(i<n/2){
            for(int j=0;j<n/2;j++){
                if(j<=i){
                    printf("+ ");
                }
                else{
                    printf("  ");
                }
            }

            for(int j=n/2;j<n;j++){
                if(j<(n-i-1)){
                    printf("  ");
                }
                else{
                    cout<<"+ ";
                }
            }
            cout<<endl;
        }
        /////////////////////
        if(i>=n/2){
            // for(int j=0;j<n-i-1;j++){
            //     printf("+ ");
            // }
            // cout<<endl;
            ///////////////////////

            for(int j=0;j<n-i-1;j++){
                if(j<i){
                    printf("+ ");
                }
                else{
                    printf("  ");
                }
            }

            // cout<<n/2<<i<<endl;
            for(int j=n/2;j<n;j++){
                // cout<<i<<" ";
                if(j>i){
                    cout<<"+ ";
                }
                else{
                    printf("  ");
                }
            }
            cout<<endl;
        }
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if (j >= i)
    //         {
    //             cout << "% ";
    //         }
    //         else
    //         {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }

    return 0;
}