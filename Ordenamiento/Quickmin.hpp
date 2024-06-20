#ifndef  QUICK_MIN_HPP
#define QUICK_MIN_HPP

int particion(int *A, int p, int r) 
{
	int x = A[r]; //el pivote
	int i = p - 1; //indice de los menores
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int minimun(int *A, int p, int r, int k)
{
	if (p == r) return A[p];
	int q = particion(A, p, r); 
	int l = q - p + 1; 
	if (k == l)
		return A[q];
	else if (k < l) {
		return minimun(A, p, q - 1, k);
	}
	else {
		return minimun(A, q + 1, r, k - l);
	}
}

#endif //! QUICK_MIN_HPP
