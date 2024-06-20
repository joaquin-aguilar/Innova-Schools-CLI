#pragma once

void Merge(int* A1, int* A2, int* A, int n) {
	int i = 0, j = 0, k = 0;
	int mitad = n / 2;
	while (i < mitad && j < n - mitad) {
		if (A1[i] < A2[j]) {
			A[k] = A1[i];
			i++; k++;
		}
		else {
			A[k] = A2[j];
			j++; k++;
		}
	}
	while (i < mitad) {
		A[k] = A1[i];
		i++; k++;
	}
	while (j < n - mitad) {
		A[k] = A2[j];
		j++; k++;
	}
}

void OrdenamientoMerge(int* A, int n) {
	if (n > 1) {
		int mitad = n / 2;
		int* A1 = new int[mitad];
		int* A2 = new int[n - mitad];

		for (int i = 0; i < mitad; i++) {
			A1[i] = A[i];
		}
		for (int i = mitad; i < n; i++) {
			A2[i - mitad] = A[i];
		}
		OrdenamientoMerge(A1, mitad);
		OrdenamientoMerge(A2, n - mitad);
		Merge(A1, A2, A, n);
		delete[] A1;
		delete[] A2;
	}
}

