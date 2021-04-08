ll phi[MAXN + 1];

void euler()
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for (ll i = 2; i <= MAXN; i++)
	{
		if (!phi[i])
		{
			for (ll j = i; j <= MAXN; j += i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}
