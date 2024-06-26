int arr[] = {3,4,6,7,9,12,14,16,17};
    int n = sizeof(arr)/sizeof(int);
    
    int target = 8;
    int low=0, high = n-1;
    int mid = 0;
    int ans = -1; // assuming it DNE
    // implementation of floor is a bit diff
    
   
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]<=target){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<ans;

// ceil --> lower bound
