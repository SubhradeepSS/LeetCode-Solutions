

int missingNumber(int* arr, int arrSize){
    int s=0;
for(int i=0;i<arrSize;i++){
    s+=arr[i];
}
    return ((arr[0]+arr[arrSize-1])*(arrSize+1))/2-s;
}

