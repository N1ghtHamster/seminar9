#include <stdio.h>

void read_file(char *str, char *filename_read)
{
	FILE *fp = fopen(filename_read, "r");
    char ch;
	if (fp)
	{
		while ((ch = fgetc(fp)) != EOF)
			*str++ = ch;
	}
}

void write_file(int count, char *filename_write)
{
	FILE *fp = fopen(filename_write, "w");
	if(fp)
    {	
		fprintf(fp, "%d", count);
		fclose(fp);
	}
}

int counter(char *str)
{
    int j = 0;
    int count = 0;
    while (str[j] != '\0')
    { 
        if (str[j] == 'a' && (str[j + 1] == ' ' || str[j + 1] == '\0'))
            count++;
        j++;
    }
    return count;
}

int main(void)
{
	char *filename_read = "data9_6.txt";
	char *filename_write = "output9_6.txt";
	char str[1000] = {0};
	int count;
	read_file(str, filename_read);
	count = counter(str);
	write_file(count, filename_write);
	return 0;
}

