#include <iostream>
#include "add.hpp"
#include <cmath>
#define ll long long
using namespace std;

const ll mod = 1e8;

int com(ll a[], ll b[], int lena, int lenb)
{
    if(lena > lenb) return 1;
    if(lena < lenb) return -1;

    for(int i = 0; i <= lena; i++)
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    
    return 0;
}

void add(ll a[], ll b[], ll ans[], int lena, int lenb, int &len_ans, bool sya, bool syb, bool &sy_ans)
{
    if(sya == syb)
    {
        len_ans = max(lena,lenb);

        for(int i = len_ans; i >= 1; i--)
        {
            if(i <= lena) ans[i] += a[i];
            if(i <= lenb) ans[i] += b[i];

            if(ans[i] >= mod)
            {
                ans[i-1] += ans[i]/mod;
                ans[i] %= mod;
            }
        }
        sy_ans = sya;
    }
    
    else
    {
        int x = com(a,b,lena,lenb);
        if(x == 1)
        {
            len_ans = lena;

            for(int i = len_ans; i >= 1; i--)
            {
                if(i <= lena) ans[i] += a[i];
                if(i <= lenb) ans[i] -= b[i];

                if(ans[i] >= mod)
                {
                    ans[i-1] += ans[i]/mod; ans[i] %= mod;
                }
                else if(ans[i] < 0)
                {
                    ans[i-1] -= 1; ans[i] += mod;
                }
            }
            sy_ans = sya;
        }
        else if(x == -1)
        {
            len_ans = lenb;

            for(int i = len_ans; i >= 1; i--)
            {
                if(i <= lena) ans[i] -= a[i];
                if(i <= lenb) ans[i] += b[i];

                if(ans[i] >= mod)
                {
                    ans[i-1] += ans[i]/mod; ans[i] %= mod;
                }
                else if(ans[i] < 0)
                {
                    ans[i-1] -= 1; ans[i] += mod;
                }
            }
            sy_ans = syb;
        }
        else
        {
            len_ans = 1; sy_ans = false;
        }
    }

    // cout<<sya<<' '<<syb<<' '<<sy_ans<<endl;
}