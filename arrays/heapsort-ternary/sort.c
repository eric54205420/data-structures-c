
#include "Item.h"

void fixUp(Item a[], int k) {
	while (k > 1 && less(a[k/2], a[k])) {
		exch(a[k], a[k/2]);
		k = k/2;
	}
}

void fixDown(Item a[], int k, int n) {
	int j;
	
	while((3*k)-1 <= n) {
		j = (3*k)-1;
		
		if (j < n && less(a[j], a[j+1])) {
			++j;
			if (j < n && less(a[j], a[j+1])) {
				++j;
			}
		} else if (j+1 < n && less(a[j], a[j+2])) {
			j += 2;
		}
		
		if (!less(a[k], a[j])) {
			break;
		}
		
		exch(a[k], a[j]);
		
		k = j;
	}
}

void heapsort(Item a[], int l, int r) {
	int k;
	int N = r-l+1;
	Item *pq = a+l-1;

	for (k = (N+1)/3; k >= 1; --k) {
		fixDown(pq, k, N);
	}
	
	while (N > 1) {
		exch(pq[1], pq[N]);
		fixDown(pq, 1, --N);
	}
}
