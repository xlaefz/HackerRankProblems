void swap(char *x, char *y)
{
    char ch = *x;
    *x = *y;
    *y = ch;
    return ;
}

void PermtnString(char *str, int start, int end)
{
    if(start == end)//nothing more left to permute 
    {
        printf("%s\n", str);
    }
    else
    {    
        int i = start;
        int j = 0;
        int flag = 0;
        
        for(; i <= end ; i++)
        {
            flag = 0;
            j = i -1 ;    
            while( j>= start)
            {
                if(str[i] == str[j])    
                {
                    flag = 1;
                    break;
                }
                j--;    
            }        
            if(flag) continue;
                
            swap(&str[start], &str[i]); 
            PermtnString(str, start+1, end);
            //swap again
            swap(&str[start], &str[i]); //backtrack step    
        } 

    }
    return ;    
}

int main()
{
    char str[50] = {0};

    printf("enter the string\n");
    
    gets(str); //better fgets should be used

    printf("Permutations of string - \n");

    PermtnString(str, 0, strlen(str)- 1);

    return 0;
}