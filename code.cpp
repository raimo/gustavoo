//Include headers
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

inline unsigned int read_integer(const char *src,unsigned int &pos)
{
    register char ch = src[pos];
    while (!isdigit(ch))
    {
        if (ch == '\n')
            return 0;
        ch = src[++pos];
    }
    unsigned int number = ch-'0';
    ch = src[++pos];
    while (isdigit(ch))
    {
        number *= 10;
        number += (ch - '0');
        ch = src[++pos];
    }
    return number;
}
inline unsigned int read_digit(const char *src,unsigned int &pos) 
{
    register char ch = src[pos];
    while (!isdigit(ch)) {
        if (ch == '\n') {
            return 0;
        }
        ch = src[++pos];
    }
    return (src[pos++] - '0');
}

unsigned long int gostavoo(const char *filename)
{
    unsigned long int nway[501]={0};
    FILE *input;
    static char buffer[20];
    unsigned int i,n,bitmask=0,k=0;
    input=fopen(filename,"r");
    fgets(buffer,20,input);
    n=read_integer(buffer,k);
    k=0;
    fgets(buffer,20,input);
    while(i=read_digit(buffer,k)) bitmask|=1<<i;
    fgets(buffer,4,input);
    k=0;
    bitmask|=(1<<(9+read_digit(buffer,k)));
    bitmask^=(1<<read_digit(buffer,k));
    fclose(input);
    nway[0] = 1;
    i=0;
    while(i<n) {
        for(k=1;k<=9;k++) {
            if(bitmask&(1<<k)) {
                if (n<i+k){    
                    bitmask^=(1<<k);
                    continue;
                }                
                nway[i+k] += nway[i];
                if(bitmask&(1<<(k+9)))
                    nway[i+k] += nway[i];
            }
        }
        i++;
    }
    return nway[n];
}