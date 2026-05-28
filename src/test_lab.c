#include    "../inc/cube_3d.h"

static char	**ft_free_split(char **tab, int count)
{
	while (count--)
		free(tab[count]);
	free(tab);
	return (NULL);
}

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_dupword(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_chat_gpt_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[index] = ft_dupword(s, j, i);
			if (!tab[index])
				return (ft_free_split(tab, index));
			index++;
		}
	}
	tab[index] = NULL;
	return (tab);
}

int main()
{
    char **tab;
    int i = 0;

    tab = ft_split("255,545,12", ',');
    while (i < 3)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}