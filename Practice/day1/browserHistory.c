#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BrowserHistory
{
    char *val;
    struct BrowserHistory *next;
    struct BrowserHistory *prev;
} BrowserHistory;

BrowserHistory *browserHistoryCreate(char *homepage)
{
    BrowserHistory *node = (BrowserHistory *)malloc(sizeof(BrowserHistory) * 1);
    node->val = homepage;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void browserHistoryVisit(BrowserHistory **obj, char *url)
{
    BrowserHistory *nextNode = (BrowserHistory *)malloc(sizeof(BrowserHistory));
    nextNode->val = url;
    nextNode->next = NULL;
    nextNode->prev = *obj;

    (*obj)->next = nextNode;
    *obj = nextNode;
    printf("=> %s\n", (*obj)->val);
}

char *browserHistoryBack(BrowserHistory **obj, int steps)
{
    while (steps > 0)
    {
        if ((*obj)->prev == NULL)
        {
            break;
        }
        else
        {
            *obj = (*obj)->prev;
            printf("%s\n", (*obj)->val);
        }

        steps--;
    }
    *obj = (*obj)->next;

    return (*obj)->val;
}

char *browserHistoryForward(BrowserHistory **obj, int steps)
{
    while (steps > 0 && (*obj)->next != NULL)
    {
        if ((*obj)->next != NULL)
        {
            *obj = (*obj)->next;
        }
        steps--;
    }
    return (*obj)->val;
}

void browserHistoryFree(BrowserHistory **obj)
{
    free(*obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* *obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(*obj, url);

 * char * param_2 = browserHistoryBack(*obj, steps);

 * char * param_3 = browserHistoryForward(*obj, steps);

 * browserHistoryFree(*obj);
 ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
 ["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]
*/
int main()
{
    BrowserHistory *b = (BrowserHistory *)malloc(sizeof(BrowserHistory) * 1);
    b = browserHistoryCreate("leetcode.com");
    browserHistoryVisit(&b, "google.com");
    browserHistoryVisit(&b, "facebook.com");
    browserHistoryVisit(&b, "youtube.com");
    printf("%s\n", browserHistoryBack(&b, 1));
    printf("%s\n", browserHistoryBack(&b, 1));
    printf("%s\n", browserHistoryBack(&b, 1));
    browserHistoryVisit(&b, "linkedin.com");
    char *s = browserHistoryForward(&b, 2);
    browserHistoryBack(&b, 2);
    browserHistoryBack(&b, 7);
    browserHistoryFree(&b);
    return 0;
}