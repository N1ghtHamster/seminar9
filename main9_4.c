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
	return 0;
}

