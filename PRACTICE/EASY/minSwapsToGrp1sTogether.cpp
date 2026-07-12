#include<bits/stdc++.h>
using namespace std;


int minSwaps(vector<int>& data) {
  int swaps = INT_MAX, n = data.size();
  int onesCnt = count(data.begin(), data.end(), 1);
  for(int i = 0; i <= n - onesCnt; i++){
      int currSwaps = 0;
      for(int j = i; j < i + onesCnt; j++) {
          if(data[j] == 0) currSwaps++;
      }
      swaps = min(swaps, currSwaps);
  }
  return swaps;
}

int minSwaps(vector<int>& data) {
  int zeroCnt = 0, n = data.size(), miniSwaps = INT_MAX;
  int onesCnt = count(data.begin(), data.end(), 1);
  int j = 0, i = 0;
  while(j < n){
      if(data[j] == 0) zeroCnt++;

      // * Check if shrinking is required
      if(j - i + 1 > onesCnt){
          if(data[i] == 0) zeroCnt--;
          i++;
      }

      if(j - i + 1 == onesCnt) miniSwaps = min(miniSwaps, zeroCnt);

      j++;
  }

  return miniSwaps;
}