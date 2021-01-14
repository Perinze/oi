// empty			0
// {i}				1 << i
// {0,1,...,n-1}	(1 << n) - 1
// if i in S		if (S >> i & 1)
// add i to S		S | 1 << i
// rm i from S		S & ~(1 << i)
// S and T			S | T
// S cross T		S & T

// iterator {0,1,...,n-1}
// for (int S = 0; S < 1 << n; S++) {
// }

// iterator subset of S
// int sub = S
// do {
//     sub = (sub - 1) & sub
// } while (sub != sup);	// after 0, will be -1 & sup == sup

// iterator subset of S with size k
// int comb = (1 << k) - 1;
// while (comb < 1 << n) {
//     int x = comb & -comb, y = comb + x;
//     comb = ((comb & ~y) / x >> 1) | y;
// }


// process i-th data
// for (int i = 0; i < 1 << n; i++) {
//     for (int j = 0; j < n; j++) {
//         if (i >> j & 1) {
//         }
//     }
// }
