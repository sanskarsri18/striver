Brute Force Approach

long long power(int b , int exp){
    long long ans = 1;
    long long base = b;
    while(exp>0){
        if(exp%2){
            exp--;
            ans = ans * base;
        }
        else{
            exp = exp / 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRoot(int n, int m) {
  for(int i = 1; i <= m; i++){
      long long val = power(i , n);
      if(val == (long long)m){
          return i;
      }
      if(val > (long long)m){
          break;
      }
  }
  return -1;
}


Optimized Approach

int NthRoot(int n, int m) {
  int s = 0;
  int e = m;
  int mid = s + (e - s) / 2;
  while(s<=e){
      long long ans = 1;
      for(int i = 0; i < n; i++){
          ans = ans * mid;
          if(ans > m){
              break;
            }
        }

        if(ans == (long long)m){
            return mid;
        }
        else if (ans > (long long)m){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return -1;
}
