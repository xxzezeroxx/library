map<long long,int> prime_factor(long long n){
	 map<long long,int> ret;
	 for (long long i=2LL ;i*i <= n;i++){
		 while(n%i==0){
		 	if (n%i==0){
				 ret[i]++;
				 n/=i;
		 	}
		 }
	 }
	 if (n != 1) ret[n]++;
	 return ret;
}