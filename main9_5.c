#include <stdio.h>
#include <ctype.h>
#include <string.h>

void read_file(char *str, char *filename_read)
{
	FILE *fp;
	fp = fopen(filename_read, "r");
	char ch;
	if (fp)
	{
		while ((ch = fgetc(fp)) != EOF)
			*str++ = ch;
		str = '\0';
	}
	fclose(fp);
}

void write_file(char *str, char *filename_write)
{
	FILE *fp;
	fp = fopen(filename_write, "w");
	if (fp)
		fprintf(fp, "%s", str);
	fclose(fp);
}
void find_max_word(char *str, char *dst)
{
	int max = 0;
	int count = 0;
	int id = 0;
	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[i] != ' ' && str[i] != EOF) 
			count++;
		else
		{
			if (count > max)
			{ 
				max = count;
				id = (i+1) - count;
			}
			count = 0;
		}
		if (count > max)
		{
			max = count;
			id = (i+1) - count;
		}
	}
	while (isalpha(str[id]))
		*dst++ = str[id++];
}
int main(void)
{
	char *filename_read = "data9_5.txt";
	char *filename_write = "output9_5.txt";
	char str[1000] = {0};
	char dst[26] = {0};
	read_file(str, filename_read);
	find_max_word(str, dst);
	write_file(dst, filename_write);
	return 0;
}

