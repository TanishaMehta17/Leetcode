int solution(char *S, char *T) {
    int n = strlen(S);
    int ans = 0 , ct = 0 ;
    bool check = true, up = true;
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == T[i]) {
            continue;
        }

        if (check) {
            check = false;
            up = S[i] > T[i];
            ind = i ;
        } else {
         
                if (S[i] > T[i]) ans++;
                else ct++;

        }
    }
    // cout<<ans<<" "<<ct<<endl;
  if(ans > ct ){
    if(up) return ct + 1;
    else{
        return ct ;
    }
  }
  else{
    if(up) return ans;
    else{
        return ans+1 ;
    }
  }
}