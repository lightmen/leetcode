// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long start,end,mid;
    start = 1;
    end = n;

    while(start <= end){
        mid = (start + end) / 2;
        if(isBadVersion(mid)){
            if(mid - 1 <= 0 || !isBadVersion(mid - 1))
                break;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return mid;
}
