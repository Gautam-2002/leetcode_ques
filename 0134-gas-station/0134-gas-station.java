class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0;
        int gas_deficit = 0;
        int current_gas = 0;
        int n = gas.length;
        for(int i=0;i<n;i++){
            current_gas += gas[i] - cost[i];
            if(current_gas < 0){
                gas_deficit += current_gas;
                start = i+1;
                current_gas = 0;
            }
        }
        if(gas_deficit + current_gas >= 0){
            return start;
        }
        return -1;
    }
}