class Eratosthenes{
public:
    std::vector<bool> prime;

    Eratosthenes(int n){
        prime.resize(n+1,true);
        prime[0] = false;
        prime[1] = false;
	    for(int i = 2; i <= n ; i++){
		    if(prime[i]){
			    for(int j = i+i; j <= n; j+=i){
				    prime[j] = false;
			    }
		    }
	    }
    }
};