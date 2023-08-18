int NthRoot(int n, int m) {
    int left = 1, right = m;
    while(left<=right){
        int mid = (left+right)/2;
        long long ll = 1;
        for( int i = 0; i < n; i++ ){
               ll *= mid;
               if(ll > m){
                  break;
               }
              
        }

        if(ll == m){
           return mid;
        }
        else if(ll>m){
            right = mid-1;
        }
        else{
          left = mid+1;
        }
    }

    return -1;
}