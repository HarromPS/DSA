/*
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *target=(int*)calloc(sizeof(int),numsSize);
    for(int i=0;i<numsSize;i++)
    {
        target[i]=-1;
    }
    for(int i=0;i<numsSize;i++)
    {
        if(target[index[i]]==-1)
        {
            target[index[i]]=nums[i];
        }
        else {
            //shifting all the elements 
            int x=index[i];
            while(target[x]!=-1 && x<numsSize){
                x++;
            }
            for(int j=x;j>=index[i]+1;j--){
                target[j]=target[j-1];
            }
            target[index[i]]=nums[i];
        }
        
    }
    *returnSize=numsSize;
    return target;
}
*/