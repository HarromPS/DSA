#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
This problem revolves around simulating a simplified UDP network protocol. 
You need to process a series of requests to send packets over the network while accounting for the following rules:

Queue Capacity (maxPackets): The network can hold a maximum of maxPackets packets in its queue at any time. 
If the queue overflows (more packets are added than maxPackets), the excess packets are dropped.

Delivery Rate (rate): The network processes packets at a constant rate of rate packets per second. 
For each second that passes, rate packets are removed from the queue and delivered to the client.

Requests: Each request is represented as [t, numPackets], meaning at time t,
numPackets packets are added to the network's queue.

requests = [[1, 8], [4, 9], [6, 7]]
maxPackets = 10
rate = 2

output: 4

t = 1 packet_remaining = 8(0+8), in_queue = 8, dropped = 0, delivered = 2
t = 2 packet_remaining = 6, in_queue = 6, dropped = 0, delivered = 2
t = 3 packet_remaining = 4, in_queue = 4, dropped = 0, delivered = 2
t = 4 packet_remaining = 11(4+9), in_queue = 10, dropped = 1, delivered = 2
t = 5 packet_remaining = 8, in_queue = 8, dropped = 0, delivered = 2
t = 6 packet_remaining = 13(6+7), in_queue = 10, dropped = 3, delivered = 2
t = 7 packet_remaining = 8, in_queue = 8, dropped = 0, delivered = 2
t = 8 packet_remaining = 6, in_queue = 6, dropped = 0, delivered = 2
t = 9 packet_remaining = 4, in_queue = 4, dropped = 0, delivered = 2
t = 10 packet_remaining = 2, in_queue = 2, dropped = 0, delivered = 2
t = 11 packet_remaining = 0, in_queue = 0, dropped = 0, delivered = 0

so total packets dropped = 4
*/

int packetsDropped(vector<vector<int>>& request, int maxPackets, int rate){
    // sort the requests as per their arrival time 
    sort(request.begin(), request.end());

    int t = 1;  // current time 
    int current_packets = 0;
    int packets_dropped = 0;

    // iterate requests and check packet drops
    int i=0;
    int n=request.size();
    while(true){
        int time = request[i][0];
        int packets = request[i][1];

        while(t < time){
            int packets_to_deliver = min(rate, current_packets);
            current_packets -= packets_to_deliver;
            t+=1;
        }

        // add this time packets 
        current_packets+=packets;

        // packets drops
        if(current_packets > maxPackets){
            packets_dropped += current_packets - maxPackets;
            current_packets = maxPackets;
        }
        i++;
        if(i>=n){
            break;
        }
    }

    // deliver packets until max time
    while(current_packets > 0){
        int packets_to_deliver = min(rate, current_packets);
        current_packets -= packets_to_deliver;
    }
    return packets_dropped;
}

void solve()
{
    int size;
    cin>>size;
    vector<vector<int>> request;    // (size * size)

    int n;  // number of requestss 
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        int packets;
        cin>>packets;
        vector<int> temp;
        temp.push_back(t);
        temp.push_back(packets);
        request.push_back(temp);
    }

    int maxPackets;
    cin>>maxPackets;
    int rate;
    cin>>rate;

    int res = packetsDropped(request,maxPackets,rate);
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