#pragma once
namespace crypto
{
	// GCD
	int gcd(int a, int b);
	int recurrentEuclid(int a, int b);
	int extendedEuclid(int a, int b);

	// Functions
	int euler(int p);
	int L(int a, int p); // Legendre symbol

	//Operations
	int addmod(int a, int b, int n);
	int mulmod(int a, int b, int n);
	int powmod(int a, int b, int n);

	// Multiplicative Group
	int** generateGroup(int n, int (*method)(int, int, int));
}