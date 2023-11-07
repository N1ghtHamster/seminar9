#include <stdio.h>
#include <string.h>

void read_file(char *str, char *filename_read)
{
	FILE *fp = fopen(filename_read, "r");
    if(fp)
    {
        fscanf(fp, "%s", str);
        fclose(fp);
    }
}

void write_file(char *str, char *filename_write)
{
	FILE *fp = fopen(filename_write, "w");
	if(fp)
    {
		fprintf(fp, "%s", str++);
		fclose(fp);
	}
}

int compare(char a, char b)
{
    if (a == b)
        return 1;
    else
        return 0;
}

void change_simvol(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
		if (compare(str[i], 'a')){str[i] = 'b';}
		else if (compare(str[i], 'b')){str[i] = 'a';}
		else if (compare(str[i], 'A')){str[i] = 'B';}
		else if (compare(str[i], 'B')){str[i] = 'A';}
		else
			continue;
    }
}

int main(void)
{
	char str[1000] = {0};
    char * filename_read = "data9_2.txt";
    char * filename_write = "output9_2.txt";
    read_file(str, filename_read);
    change_simvol(str);
    write_file(str, filename_write);
    return 0;
}

