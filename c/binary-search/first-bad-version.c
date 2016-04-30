// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start,end,mid;
    start = 1;
    end = n;

    while(start < end){
        mid = start + (end - start) / 2;
        if(isBadVersion(mid)){
            end = mid;
        }else{
            start = mid + 1;
        }
    }

    return end;
}
