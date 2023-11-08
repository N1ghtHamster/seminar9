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

void strcopy(char *str, char *dst)
{
	char ch;
	while ((ch = *str++) != '\0')
	{
		if (isalpha(ch))
			*dst++ = ch;
	}
	dst = '\0';
}

void del(char *str, char *dst)
{
    char ch;
    int j = 0;
    while ((ch = *str++) != '\0')
    {
        if (strchr(dst,ch) == NULL && ch != ' ')
        {
            dst[j] = ch;
            j++;
        }
    }
    dst[j] = '\0';
}

int main(void)
{
	char *filename_read = "data9_4.txt";
	char *filename_write = "output9_4.txt";
	char str[1000] = {0};
	char dst[26] = {0};
	read_file(str, filename_read);
	del(str, dst);
	write_file(dst, filename_write);
	printf("%s\n", str);
	printf("%s\n", dst);
	return 0;
}

