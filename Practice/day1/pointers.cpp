// #include <iostream>
// #include <cstdio>
// using namespace std;

// void function(int **arr)
// {
//     // cout<<arr[1]+1<<endl;   // address
//     // cout<<*arr[1]<<endl;  // *a[1] + 1=> *(116 i.e address)=> 116 + 1(1*sizeof(int)) >
//     // cout<<arr<<" "<<arr+1<<endl;
//     // cout<<*arr[1]<<endl;  // *a[1] / a[1] => *(116 i.e address)=> 15

//     cout<<*arr<<endl;
//     cout<<arr[0]<<endl;

//     cout<<*arr+1<<endl;
//     cout<<arr[0]+1<<" "<<arr[1][0]<<endl;

//     // cout << *(*arr) << endl;
//     // cout << (*(*arr) + 1) << endl;
//     // cout << *(arr + (1 * 4 * sizeof(int))) << endl;
//     // for (int c = 0; c < 3; c++)
//     // {
//     //     for (int r = 0; r < 4; r++)
//     //     {
//     //         if (r == c)
//     //         {
//     //             // printf("%d ",*(*(arr+r)+c)+7);
//     //             printf("%d ", *(*(arr + r) + c));
//     //             // printf("%d ",((arr+r)+c));
//     //         }
//     //     }
//     // }
// }
// int main()
// {
//     // declare pointer of int * pointer
//     int **array;

//     // allocate table of size = no of rows
//     array = (int **)malloc(sizeof(int *) * 3);

//     // allocate momory for each row
//     for (int i = 0; i < 3; i++)
//     {
//         array[i] = (int *)malloc(sizeof(int) * 1);
//     }
//     array[0][0] = 21;
//     array[0][1] = 22;
//     array[0][2] = 32;
//     array[0][3] = 42;

//     array[1][0] = 15;
//     array[1][1] = 16;
//     array[1][2] = 17;
//     array[1][3] = 18;

//     array[2][0] = 49;
//     array[2][1] = 40;
//     array[2][2] = 41;
//     array[2][3] = 42;

//     function(array);
//     return 0;
// }

#include <iostream>
#include <cstdio>
using namespace std;

// Pointer Arithmetics
// ++, --, +, -
int main()
{

    int a = 21;
    int *ptr;
    ptr = &a;   // let p = 100

    // *ptr=10;
    // ptr++;
    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<ptr<<endl;
    // printf("%d\n",a);
    // printf("%d\n",&a);
    // printf("%d\n",ptr);
    // printf("%d %d\n",(ptr++));  // ptr=100 ++ptr => 104 *104
    // printf("%d ",&a);   // a=21 correct
    // printf("%d\n",*ptr);
    // int arr[]={1,2,3,4,5};
    // int *p=&arr[0];
    // for(int i=0;i<5;i++){
    //     // cout<<&arr[i]<<" ";
    //     // printf("%d ",&arr[i]);
    //     printf("%d %d\n",p,&arr[i]);
    //     p++;
    // }
    // printf("%d %d %d %d\n", ptr, ptr--, ptr++, ++ptr);
    // printf("%d\n",ptr);
    // printf("%d\n",ptr++);
    // printf("%d %d \n",ptr,++ptr);

    // such type of code writing should be avoided
    // int b=11;
    // printf("%d\n",b++);
    // printf("%d %d %d\n",b,b++,++b);
    // b=11;
    // printf("%d ",b);
    // printf("%d ",b++);
    // printf("%d ",++b);

    // getting the values
    // arr[i] == *(arr+i)
    // e.g arr = [1,2,3,4,5];  i.e [100,104,108,112,116] arr = 100
    // arr[2] => *(arr + 2) => *(100 + 2*sizeof(arr))
    // => *(100 + 2*4) => *(100 + 8) => *(108)
    // => 3

    // int arr[] = {1, 2, 3, 4, 5};
    // printf("%d %d %d\n", arr, &arr[0], &(*(arr + 0)));
    // printf("%d %d\n", arr[2], *(arr + 2));     // => 3 3
    // printf("%d %d\n", &arr[2], &(*(arr + 2))); // => 3 3

    // printf("%d\n",ptr);
    // printf("%d\n",ptr+1);   // ptr + 1=> ptr + 1*sizeof(p) - int(4 bytes) => p+1*(4)
    // printf("%d\n",ptr++);
    // printf("%d\n",ptr+2);
    // printf("%d\n",ptr-2);
    int array[3][3] = { // deferencing => (*(baseAddress + (i * n)) + j*sizeof(type))
        {6, 2, 5},
        {0, 1, 3},
        {4, 9, 8}
    };
    // (*(baseAddress + (i * n)) + j*sizeof(type))
    // where i=> row no
    //       n=> col size
    //       j=> col no

    // ans => 5
    // printf("%d \n",*(*(array+0)+2));

    printf("%d %d %d %d %d\n",array,&array,*(*array),array[0],&array[0]);
    printf("%d %d\n",(*(array)+1),&array[1][0]);
    printf("%d %d\n",*(*(array+1)+1),array[1][1]);
    return 0;
}
