int phi[MAXN + 1];

void getphi()
{
	memset(phi, 0, sizeof(phi));
	for (int i = 2; i <= MAXN; i++)
	{
		if (!phi[i])
		{
			for (int j = i; j <= MAXN; j += i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}
