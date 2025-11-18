long fibo(int n){
    if(n==0 || n==1){return n;}
    else{return fibo(n-1)+fibo(n-2);}
}

long fibo_dyn(int n, long table[]){
    if(table[n]==-1){
        if(n==0||n==1){table[n]= n;}
        else{table[n]=fibo_dyn(n-1,table)+fibo_dyn(n-2,table);}
    }
    return table[n];
}

