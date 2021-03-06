#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int Max = 20001;
 
int  num[Max];
int sa[Max], ranks[Max], height[Max];
int wa[Max], wb[Max], wv[Max], wd[Max];
 
int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}
 
void da(int *r, int n, int m){         
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}
 
void calHeight(int *r, int n){           
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) ranks[sa[i]] = i;
    for(i = 0; i < n; height[ranks[i ++]] = k){
        for(k ? k -- : 0, j = sa[ranks[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}
 
int main(){
    char str[Max];
    int i, m=30, ans,len,h;
    while(scanf("%s",str)!=EOF){
        len=strlen(str);
        for(i=0;i<=len;i++)num[i]=str[i]-'a'+1;
        num[len]=0;
        da(num, len + 1, m);
        calHeight(num, len);
        ans=0;
        for(i=1;i<len;i++){
            h=height[i+1];
            ans+=(len-sa[i])-h;
        }
        ans+=len-sa[len];
        cout<<ans<<endl;
    }
    return 0;
}