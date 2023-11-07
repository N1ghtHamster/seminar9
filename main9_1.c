#include <stdio.h>
#include <string.h>

void read_file(char *str1, char *str2, char *filename_read)
{
	FILE *fp = fopen(filename_read, "r");
    if(fp)
    {
        fscanf(fp, "%s%s", str1, str2);
        fclose(fp);
    }
}

void write_file(char *str, char *filename_write)
{
	FILE *fp = fopen(filename_write, "w");
	if(fp)
    {
		while (*str != 0)
		{
			fprintf(fp, "%c ", *str++);
		}
		fclose(fp);
	}
}

void is_one_char_in_word(char *str1, char *str)
{
	char c;
	int t;
    for (int i = 0; i < strlen(str1); i++)
    {
		t = 0;
		c = str1[i];
        for (int j = 0; j < strlen(str1); j++)
        {
            if (str1[i] == str1[j])
            {
				t++;
				continue;
			}	
        }
        if (t == 1)
			*str++ = c;
    }
}

void end_str(char *str_w1, char *str_w2, char *str_end)
{
	char c;
	int t;
    for (int i = 0; i < strlen(str_w1); i++)
    {
		t = 0;
		c = str_w1[i];
        for (int j = 0; j < strlen(str_w2); j++)
        {
            if (str_w1[i] == str_w2[j])
            {
				t++;
				continue;
			}	
        }
        if (t == 1)
			*str_end++ = c;
    }
}

void sort_array(char *str)
{
    char tmp;
    for (int j = 0; j < strlen(str); j++)
    {
        tmp = str[j];
        if (str[j + 1] != '\0')
		{	
			if (tmp > str[j + 1])
			{
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
		}
    }
}

int main(void)
{
	char str1[100] = {0};
	char str2[100] = {0};
	char str_w1[26] = {0};
	char str_w2[26] = {0};
	char str_end[26] = {0};
    char * filename_read = "data9_1.txt";
    char * filename_write = "output9_1.txt";
    read_file(str1, str2, filename_read);
    is_one_char_in_word(str1, str_w1);
    is_one_char_in_word(str2, str_w2);
    end_str(str_w1, str_w2, str_end);
    sort_array(str_end);
    write_file(str_end, filename_write);
    return 0;
}
