while(low <= high) {
    int mid = (low + high) / 2;
    // search space is already sorted
    // then always arr[low] is will be smaller
    // in that search space
    if(arr[low] <= arr[high]) {
        if(arr[low] < ans) {
            index = low;
            ans = arr[low];
        }
        break;
    }

    if(arr[low] <= arr[mid]) {
        if(arr[low] < ans) {
            index = low;
            ans = arr[low];
        }
        low = mid + 1;
    } else {
        high = mid - 1;
        if(arr[mid] < ans) {
            index = mid;
            ans = arr[mid];
        }
    }
}
return index;
