#include "crypto.h"
#include <iostream>

//GCD
int crypto::gcd(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw std::invalid_argument("a or b should be greater than 0");
	}
	while (a != b)
	{
		if (a > b) 
		{
			a -= b;
		}
		else if (b > a)
		{
			b -= a;
		}
	}
	return a;
}

int crypto::recurrentEuclid(int a, int b)
{
	int temp;
	if (b > a)
	{
		temp = b;
		b = a;
		a = temp;
	}
	while (a != 0)
	{
		temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}

int crypto::extendedEuclid(int a, int b)
{
	// TODO
	return 0;
}

// Functions

int crypto::euler(int p)
{
	int count = 0;
	for (int i = 1; i < p; i++)
	{
		if (crypto::gcd(i, p) == 1)
		{
			count++;
		}
	}
	return count;
}

int crypto::L(int a, int p)
{
	/*
		Returns:
		1 - quadratic deduction
		-1 - Not a quadratic deduction
		0 = a | p
	*/
	int x = crypto::powmod(a, (p-1)/2, p);
	return (x == p - 1) ? -1 : x;
}

// Operations
int crypto::addmod(int a, int b, int n)
{
	return (a + b) % n;
}

int crypto::mulmod(int a, int b, int n)
{
	return (a * b) % n;
}

int crypto::powmod(int a, int b, int n)
{
	if (b == 0)
	{
		return 1;
	}
	int r = 1;
	while (b)
	{
		if (b & 0x01)
		{
			r = (r * a) % n;
		}
		a = (a * a) % n;
		b >>= 1;
	}
	return r;
}

// GROUP
int** crypto::generateGroup(int n, int (*method)(int,int,int))
{
	int** group = new int*[n];
	for (int i = 0; i < n; i++)
	{
		group[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			group[i][j] = (*method)(i,j,n);
		}
	}
	return group;
}
