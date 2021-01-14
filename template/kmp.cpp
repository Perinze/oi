string pattern;
int next[MAX_P];

void init()
{
	next[0] = 0;
	next[1] = 1;
	for (int i = 2; i < pattern.size(); i++)
	{
		string pre_str = pattern.substr(0, i);
		int s;
		for (s = 1; s <= pre_str.size() / 2; s++)
		{
			string left_str = pre_str.substr(0, s);
			string right_str = pre_str.substr(substr.size() - s, s);
			if (left_str != right_str) break;
		}
		next[i] = s + 1;
	}
}
