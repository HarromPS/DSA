#include <iostream>
#include <cstdio>
using namespace std;

typedef struct BrowserHistory
{
    char *val[5001];
    int top;
} BrowserHistory;

BrowserHistory *browserHistoryCreate(char *homepage)
{
    BrowserHistory *obj = (BrowserHistory *)malloc(sizeof(BrowserHistory) * 1);
    obj->top++;
    obj->val[obj->top] = homepage;
    return obj;
}

void browserHistoryVisit(BrowserHistory *obj, char *url)
{
    obj->top++;
    obj->val[obj->top] = url;
}

char *browserHistoryBack(BrowserHistory *obj, int steps)
{
    int x = obj->top - 1;
    for (int i = steps; i > 0; i--)
    {
        x--;
        if (x < 0)
        {
            x = 0;
            break;
        }
    }
    obj->top = x + 1;
    return obj->val[x];
}

char *browserHistoryForward(BrowserHistory *obj, int steps)
{
    int x = obj->top - 1;
    for (int i = 1; i <= steps; i++)
    {
        x++;
    }
    obj->top = x + 1;
    return obj->val[x];
}

void browserHistoryFree(BrowserHistory *obj)
{
    free(obj);
}

int main()
{
    BrowserHistory *b = (BrowserHistory *)malloc(sizeof(BrowserHistory) * 1);
    b = browserHistoryCreate("leetcode.com");
    browserHistoryVisit(b, "google.com");
    browserHistoryVisit(b, "facebook.com");
    browserHistoryVisit(b, "youtube.com");
    printf("%s\n", browserHistoryBack(b, 1));
    printf("%s\n", browserHistoryBack(b, 1));
    printf("%s\n", browserHistoryBack(b, 1));
    browserHistoryVisit(b, "linkedin.com");
    char *s = browserHistoryForward(b, 2);
    browserHistoryBack(b, 2);
    browserHistoryBack(b, 7);
    browserHistoryFree(b);
    return 0;
}

// in JAVA
/*
    String stack[];
    int top;

    public BrowserHistory(String homepage) {
        stack=new String[5001];
        for(int i=0;i<100;i++){
            stack[i]=null;
        }
        top=-1;
        stack[++top]=homepage;
    }

    public void visit(String url) {
        top++;
        stack[top]=url;
        int i=top+1;
        while(stack[i]!=null){
            stack[i]=null;
            i++;
        }
    }

    public String back(int steps) {
        if(top-steps < 0){
            top=0;
            return stack[top];
        }
        top=top-steps;
        return stack[top];
    }

    public String forward(int steps) {
        if(stack[top+steps]==null){
            int i=top;
            while(stack[i]!=null){
                i++;
            }
            top=i-1;
            return stack[top];
        }
        top+=steps;
        return stack[top];
*/

// In C++
/*
    string stack[5001];
    int top;
	BrowserHistory(string homepage) {
        for(int i=0;i<100;i++){
            stack[i]="\0";
        }
        top=-1;
        stack[++top]=homepage;
    }

    void visit(string url) {
        top++;
        stack[top]=url;
        int i=top+1;
        while(stack[i]!="\0"){
            stack[i]="\0";
            i++;
        }
    }

    string back(int steps) {
        if(top-steps < 0){
            top=0;
            return stack[top];
        }
        top=top-steps;
        return stack[top];
    }

    string forward(int steps) {
        if(stack[top+steps]=="\0"){
            int i=top;
            while(stack[i]!="\0"){
                i++;
            }
            top=i-1;
            return stack[top];
        }
        top+=steps;
        return stack[top];
    }
*/