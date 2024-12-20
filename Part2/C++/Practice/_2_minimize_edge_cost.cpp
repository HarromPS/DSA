#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
This problem revolves around optimizing the purchase of resources for an edge computing environment. 
You need to decide how to buy edge devices, input peripherals, and bundles (which include one edge device and one input peripheral each) in such a way that:

The number of edge devices is at least x.
The number of input peripherals is at least y.
The total cost is minimized.

Input Explanation

You are given:

edgeDeviceCost: Cost of a single edge device.
inputPeripheralCost: Cost of a single input peripheral.
bundleCost: Cost of a single bundle (includes 1 edge device + 1 input peripheral).
x: The required number of edge devices.
y: The required number of input peripherals.

Your Task

Write a function to calculate 
the minimum expenditure required to meet or exceed the requirements x and y while minimizing the cost.

Input:

edgeDeviceCost = 3
inputPeripheralCost = 2
bundleCost = 1
x = 4
y = 3

output: 4

we can but 4 bundle cost i.e 4 device and 4 input at cost 1,so total = 4
now remaining device = 0 and input = 0
so output is 4

so bundle 0 i.e no bundle purchased yet 
    so remaining_device = device - bundle (4-0) 4
       remaining_inputs = inputs - bundle (3-0) 3
       cost = 0 * 1 + 3 * 4 + 2 * 3 = 18

so bundle 1 i.e 1 purchased
    so remaining_device = device - bundle (4-1) 3
       remaining_inputs = inputs - bundle (3-1) 2
       cost = 1 * 1 + 3 * 3 + 2 * 2 = 14

so bundle 2 
    so remaining_device = device - bundle (4-2) 2
       remaining_inputs = inputs - bundle (3-2) 1
       cost = 2 * 1 + 3 * 2 + 2 * 1 = 10

so bundle 3
    so remaining_device = device - bundle (4-3) 1
       remaining_inputs = inputs - bundle (3-3) 0
       cost = 3 * 1 + 3 * 1 + 2 * 0 = 6

so bundle 4
    so remaining_device = device - bundle (4-4) 0
       remaining_inputs = inputs - bundle (3-4) 0 max(0, input-bundle)
       cost = 4 * 1 + 3 * 0 + 2 * 0 = 4


edgeDeviceCost = 1
inputPeripheralCost = 2
bundleCost = 4
x = 2
y = 1

so bundle 0 i.e no bundle purchased yet 
    so remaining_device = device - bundle (2-0) 2
       remaining_inputs = inputs - bundle (1-0) 1
       cost = 0 * 4 + 2 * 1 + 1 * 2 = 4

so bundle 1 i.e 1 purchased
    so remaining_device = device - bundle (2-1) 1
       remaining_inputs = inputs - bundle (1-1) 0
       cost = 1 * 4 + 1 * 1 + 0 * 2 = 5

so bundle 2 
    so remaining_device = device - bundle (2-2) 0
       remaining_inputs = inputs - bundle (1-2) 0
       cost = 2 * 4 + 0 * 1 + 0 * 1 = 8

so min cost is 4, by purchasing 0 bundles and 2 device cost 1 and 1 input cost 2 so 4


*/

int minExpenditureCost(int edgeDeviceCost,int inputPeripheralCost,int bundleCost,int x,int y){
    int minCost = INT_MAX;

    // how many bundles we need at max
    int maxBundles = max(x,y);

    // so cost of each bundle is given as
    for(int bundle = 0;bundle<=maxBundles;bundle++){
        // remaining devices and inputs 
        int remaining_device = max(0, x - bundle);
        int remaining_input = max(0, y - bundle);

        int cost = (bundle * bundleCost) + (remaining_device * edgeDeviceCost) + (remaining_input * inputPeripheralCost);

        minCost = min(minCost, cost);
    }

    return minCost;
}

void solve()
{
    int edgeDeviceCost = 3;
    int inputPeripheralCost = 2;
    int bundleCost = 1;
    int x = 4;
    int y = 3;
    int res=minExpenditureCost(edgeDeviceCost,inputPeripheralCost,bundleCost,x,y);
    cout<<res<<endl;

}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}