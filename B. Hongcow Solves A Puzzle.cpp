#include <limits.h>
#include <stdio.h>

int main() {
	int i, j, n, m, cnt, imin, jmin, imax, jmax;
	static char cc[500][501];

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", cc[i]);
	imin = jmin = INT_MAX;
	imax = jmax = 0;
	cnt = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (cc[i][j] == 'X') {
				cnt++;
				if (imin > i)
					imin = i;
				if (imax < i)
					imax = i;
				if (jmin > j)
					jmin = j;
				if (jmax < j)
					jmax = j;
			}
	printf("%s\n", (imax - imin + 1) * (jmax - jmin + 1) != cnt ? "NO" : "YES");
	return 0;
}
