#pragma once
#include <iostream>
#include <cmath>
#define ll long long

int com(ll a[], ll b[], int lena, int lenb);
void AddForInt(ll a[], ll b[], ll ans[], int lena, int lenb, int &len_ans, bool sya, bool syb, bool &sy_ans);
void AddForDec(ll a[], ll b[], ll ans[], int lena, int lenb, int &len_ans, bool sya, bool syb, bool &sy_ans);