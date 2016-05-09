int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int i;
    int cur = 0;
    int ret = 0;
    int sum = 0;

    for(i = 0; i < gasSize; ++i){
        cur += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if(cur < 0){
            cur = 0;
            ret = i+1;
        }
    }

    return sum < 0 ? -1 : ret;
}
