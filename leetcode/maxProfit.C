


int maxProfit(vector<int> &prices){
  int min=0, max=0, maxDiff=0;

  int diff;
  for(int i=0; i<prices.size(); i++){
    diff= prices[i] - prices[min];
    if(diff<0)min=i;
    if(diff>maxDiff){
      maxDiff=diff;
      max=i;
    }
  }
  return maxDiff;
}

/*
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit2(vector<int> &prices){
  int p=0;
  for(int i=1; i<prices.size(); i++){
    int diff=prices[i] - prices[i];
    if(diff>0) p+= diff;
  }
  return p;
}

/*
Solution: we divide the whole sequence into two parts at each i, find the maximum intervals or profits in both left and right parts, add both of them together to get the maximum profit on this division. Then we select the largest one. We employ DP to solve this problem [another good explanation can be found here].
*/

    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int n=prices.size();
        
        //compute the max profit until right now
        vector<int> history(n,0);
        int currMin=prices[0];
        for(int i=1; i<n; i++){
            currMin = min(currMin, prices[i]);
            history[i]=max(history[i-1], prices[i]-currMin);
        }
        //compute the max Profit from now on;
        vector<int> future(n,0);
        int currMax=prices[n-1];
        for(int i=n-2; i>=0; i--){
            currMax = max( currMax, prices[i]);
            future[i] = max(future[i+1], currMax-prices[i]);
        }
        
        //select the maximum overall profit
        int maxProfit=0;
        for(int i=0; i<n; i++)
            maxProfit=max(maxProfit, history[i]+future[i]);
        return maxProfit;
        
    }
