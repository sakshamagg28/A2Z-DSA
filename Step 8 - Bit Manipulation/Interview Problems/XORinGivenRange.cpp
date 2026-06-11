class Solution{	
	public:
        int xorTillN(int n){
            if (n % 4 == 0) return n;
            if (n % 4 == 1) return 1;
            if (n % 4 == 2) return n + 1;
            else return 0;
        }
        
		int findRangeXOR(int l,int r){
			//your code goes here
            return xorTillN(r) ^ xorTillN(l-1);
		}
};