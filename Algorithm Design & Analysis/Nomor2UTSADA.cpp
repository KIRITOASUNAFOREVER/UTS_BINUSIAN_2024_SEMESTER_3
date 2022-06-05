#include <stdio.h>

int findMissingUtil(int arr[], int low, int high, int diff){
    // if index out of range
	if (high <= low)
        return 2147483627;
    // find the middle index
	int mid = low + (high - low)/2;
    // check the difference of middle element with its right neighbor
    if (arr[mid+1] - arr[mid] != diff)
        return (arr[mid] + diff);
    // check the difference of middle element with its left neighbor
	if (mid > 0 && arr[mid] - arr[mid-1] != diff)
        return (arr[mid-1] + diff);
    // if the missing element lies on the right subarray, reduce our search space to the right subarray nums[mid+1…high]
	if (arr[mid] == arr[0] + mid*diff)
        return findMissingUtil(arr, mid+1, high, diff);
    // if the missing element lies on the left subarray, reduce our search space to the left subarray nums[low…mid-1]
	return findMissingUtil(arr, low, mid-1, diff);
}

int findMissing(int arr[], int n){
    int diff = (arr[n-1] - arr[0])/n;
    return findMissingUtil(arr, 0, n-1, diff);
}

int main(){
	//SAMPLE INPUT & OUTPUT
    int arr[] = {120001,120013,120025,120037,120049,120061,120085,120097,120109,120121};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("SAMPLE TEST CASE : ");
	for(int i = 0; i < n ; i++){
		if(i){
			printf(" ");
		}
	   	printf("%d",arr[i]);
	}
	printf("\n");
    printf("Output = %d", findMissing(arr, n));
    
    // MY OWN TEST CASE 1
    printf("\n\n");
    int input1[] = {5, 7, 9, 11, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35};
    int jumlah1 = sizeof(input1)/sizeof(input1[0]);
    printf("TEST CASE 1 : ");
	for(int i = 0; i < jumlah1 ; i++){
		if(i){
			printf(" ");
		}
	   	printf("%d",input1[i]);
	}
	printf("\n");
    printf("Output = %d", findMissing(input1, jumlah1));
    
    // MY OWN TEST CASE 2
    printf("\n\n");
    int input2[] = {1, 4, 7, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46};
    int jumlah2 = sizeof(input2)/sizeof(input2[0]);
    printf("TEST CASE 2 : ");
	for(int i = 0; i < jumlah2 ; i++){
		if(i){
			printf(" ");
		}
	   	printf("%d",input2[i]);
	}
	printf("\n");
    printf("Output = %d", findMissing(input2, jumlah2));
    
    // MY OWN TEST CASE 3
    printf("\n\n");
    int input3[] = {1, 6, 11, 16, 21, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76};
    int jumlah3 = sizeof(input3)/sizeof(input3[0]);
    printf("TEST CASE 3 : ");
	for(int i = 0; i < jumlah3 ; i++){
		if(i){
			printf(" ");
		}
	   	printf("%d",input3[i]);
	}
	printf("\n");
    printf("Output = %d", findMissing(input3, jumlah3));
    
    return 0;
}
