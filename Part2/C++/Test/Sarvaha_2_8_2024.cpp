#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement: 

There is flood in the city, 2 helicopters are on the mission to rescue
three categories of citizens are there
3 - seniors
2 - lady/childrens
1 - males

both helicopters can carry 6 people at a time
priority of people to enter the chopper is -> 1<2<3

some people are standing in a queue in front of both copters 
more people are standing nearby
add the extra standing people in the queue 

return the both the queues after adding people 

e.g 

Input: 
0 0 0 1 3 3 Helicopter_1
0 0 1 2 3 3 Helicopter_2
3 2 4 (senior ladies/childrens males)

Output: 
2 2 3 3 3 3 
1 2 3 3 3 3 




*/
void solve()
{
    // Solution: 

    // gather all the category citizens
    map<int,int> people_freq;
    people_freq[1]=0;   // initially
    people_freq[2]=0;
    people_freq[3]=0;

    int n1=6, n2=6;

    // from 1st queue
    for(int i=0;i<n1;i++){
        int ip;
        cin>>ip;
        if(ip!=0){
            people_freq[ip]++;
        }
    }

    // from 2nd queue
    for(int i=0;i<n2;i++){
        int ip;
        cin>>ip;
        if(ip!=0){
            people_freq[ip]++;
        }
    }

    // extra standing people
    for(int i=0;i<3;i++){
        int ip;
        cin>>ip;
        if(ip!=0){
            people_freq[3-i]+=ip;
        }
    }

    // segregate people for h1 and h2
    auto seniors = people_freq.find(3)->second;
    auto ladies = people_freq.find(2)->second;
    auto males = people_freq.find(1)->second;

    // seniors for copter 1 & 2
    int h1_sen = seniors/2;
    int h2_sen = seniors/2;
    if(seniors%2==1){
        h1_sen = (seniors/2)+1;
        h2_sen = (seniors/2);
    }

    // ladies for copter 1 & 2
    int h1_lad = ladies/2;
    int h2_lad = ladies/2;
    if(ladies%2==1){
        h1_lad = (ladies/2)+1;
        h2_lad = (ladies/2);
    }

    // males for copter 1 & 2
    int h1_males = males/2;
    int h2_males = males/2;
    if(males%2==1){
        h1_males = (males/2)+1;
        h2_males = (males/2);
    }

    // helicopter 1 and 2 
    vector<int> h1,h2;

    // fill seniors
    while(h1_sen>0){
        h1.push_back(3);
        h1_sen--;
    }
    while(h2_sen>0){
        h2.push_back(3);
        h2_sen--;
    }

    // fill ladies
    while(h1_lad>0){
        h1.push_back(2);
        h1_lad--;
    }
    while(h2_lad>0){
        h2.push_back(2);
        h2_lad--;
    }

    // fill males
    while(h1_males>0){
        h1.push_back(1);
        h1_males--;
    }
    while(h2_males>0){
        h2.push_back(1);
        h2_males--;
    }

    // fill empty spaces
    int x = h1.size();
    while(x<6){
        h1.push_back(0);
        x++;
    }

    x = h2.size();
    while(x<6){
        h2.push_back(0);
        x++;
    }

    vector<int> a1,a2;
    for(int i=0;i<h1.size() && i<6;i++){
        a1.push_back(h1[i]);
    }

    for(int i=0;i<h2.size() && i<6;i++){
        a2.push_back(h2[i]);
    }

    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    for(int i=0;i<a1.size();i++){
        cout<<a1[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<a2.size();i++){
        cout<<a2[i]<<" ";
    }
    cout<<endl;
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
