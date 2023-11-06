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
		fprintf(fp, "%s ", str);
		fclose(fp);
	}
}

void is_one_char_in_word(char *str1, char *str)
{
	char c;
	int t = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
		c = str1[i];
        for (int j = i; j < strlen(str1) - 1; j++)
        {
            if (str1[i] == str1[j + 1])
            {
				t++;
				break;
			}	
        }
        if (t == 0)
			*str++ = c;
    }
}

void end_str(char *str_w1, char *str_w2, char *str_end)
{
	char c;
	int t = 0;
    for (int i = 0; i < strlen(str_w1); i++)
    {
		t = 0;
		c = str_w1[i];
        for (int j = 0; j < strlen(str_w2); j++)
        {
            if (str_w1[i] == str_w2[j])
            {
				t++;
				break;
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
    char * filename_read = "data.txt";
    char * filename_write = "output.txt";
    read_file(str1, str2, filename_read);
    printf("%s\t%llu\t%llu\n", str1, strlen(str1), sizeof(str1));
	printf("%s\t%llu\t%llu\n", str2, strlen(str2), sizeof(str2));
    is_one_char_in_word(str1, str_w1);
    is_one_char_in_word(str2, str_w2);
    end_str(str_w1, str_w2, str_end);
    sort_array(str_end);
    printf("%s\t%llu\t%llu\n", str_w1, strlen(str_w1), sizeof(str_w1));
    printf("%s\t%llu\t%llu\n", str_w2, strlen(str_w2), sizeof(str_w2));
    printf("%s\t%llu\t%llu\n", str_end, strlen(str_end), sizeof(str_end));
    write_file(str_end, filename_write);

    return 0;
}
