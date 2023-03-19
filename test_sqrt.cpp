#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    void refresh(char* one,char* two,long long two_size,int n,long long index)
    {
        char* copy_two_2=(char*)malloc((index+1));
        memset(copy_two_2,0,(index+1));
        char c=0;
        long long cal=index;
        for (long long i = (two_size-1); i >= 0; i--)
        {
            char tmp=two[i]*n+c;
            copy_two_2[cal]=tmp%10;
            cal--;
            c=tmp/10;
        }
        char b=0;
        for (long long  i = index; i >= 0; i--)
        {
            int temp=one[i]-copy_two_2[i]-b;
            if (temp<0)
            {
                temp+=10;
                b=1;
            }
            else
            {
                b=0;
            }
            one[i]=((char)temp);
        }

     // free(copy_two_2);

    }

int compare(char *two,int n,long long two_size,char* one,long long index)
    {
        long long size=0;
        if (two_size>(index+1))
        {
            size=two_size;
        }
        else
        {
            size=index+1;
        }
        char* copy_two=(char*)malloc(size);
        memset(copy_two,0,size);
        char c=0;
        long long cal=size-1;
        for (long long i = two_size-1; i >= 0; i--)
        {
            char tmp=two[i]*n+c;
            copy_two[cal]=tmp%10;
            cal--;
            c=tmp/10;
        }

        char* copy_one=(char*)malloc(size);
        memset(copy_one,0,size);
        long long cal2=size-1;
        for (long long i = index; i >=0 ; i--)
        {
            copy_one[cal2]=one[i];
            cal2--;
        }
        for (long long i = 0; i < size; i++)
        {
            if (copy_two[i]>copy_one[i])
            {
                  //  free(copy_one);
                  //  free(copy_two);
                return 1;
            }
            else if (copy_two[i]<copy_one[i])
            {
               // free(copy_one);
               // free(copy_two);
                return 0;
            }
            
            
        }
     //  free(copy_one);
      // free(copy_two);
        return 0;
    }

class numbers
{
public:
    long long size;
    char* integer;
    char* decimal;


    numbers(long long n=100,char* strSource=NULL)
    {
        if (n<=0)
        {
            printf("size error\n");
            exit(-1);
        }
        
        (this->size)=n;
        (this->integer)=(char*)malloc((this->size));
        (this->decimal)=(char*)malloc((this->size));
        if(strSource==NULL)
        {
            memset((this->integer),0,(this->size));
            memset((this->decimal),0,(this->size));
        }
        else
        {
            memset((this->integer),0,(this->size));
            memset((this->decimal),0,(this->size));
            long long point=-1;
            for (long long i = 0; strSource[i]!='\0'; i++)
            {
                if (strSource[i]=='.')
                {
                    point=i;
                    break;
                }
            }
            if (point==-1)
            {
               printf("input fatmat error\n");
               exit(-1);
            }
            long long ii=0;
            for (long long i = ((this->size)-point); i < (this->size); i++)
            {
                (this->integer)[i]=strSource[ii]-'0';
                ii++;
            }
            
            for (long long i = 0;strSource[i+point+1]!='\0'; i++)
            {
                this->decimal[i]=strSource[i+point+1]-'0';
            }
            
            if (strSource[0]=='+')
            {
               (this->integer)[(this->size)-point]=0; 
            }
            else if (strSource[0]=='-')
            {
                (this->integer)[(this->size)-point]=0;
                for (long long i = 0; i < (this->size); i++)
                {
                    (this->decimal)[i]=9-((this->decimal)[i]);
                    (this->integer)[i]=9-((this->integer)[i]);
                }

                int cc=1;
                for (long long i = (this->size)-1; i >=0; i--)
                {
                    char ttmmpp=((this->decimal)[i]+cc);
                    (this->decimal)[i]=ttmmpp%10;
                    cc=ttmmpp/10;
                }
                for (long long i = (this->size)-1; i >=0; i--)
                {
                    char ttmmpp=((this->integer)[i]+cc);
                    (this->integer)[i]=ttmmpp%10;
                    cc=ttmmpp/10;
                }

            }
            else
            {
                printf("signal error\n");
                exit(-1);
            }
            
            
            
        }
        
    }
    
    
    numbers(const numbers& copySource)
    {
        this->size=copySource.size;
        this->integer=(char*)malloc(this->size);
        this->decimal=(char*)malloc(this->size);
        for (long long i = 0; i < this->size; i++)
        {
            this->integer[i]=copySource.integer[i];
            this->decimal[i]=copySource.decimal[i];
        }
        
    }
    
    
    ~numbers()
    {
        //free((this->integer));
       // free((this->decimal));
    }
    
    
    numbers operator=(const numbers &other)
    {
        if ((this->size) != (other.size))
        {
            printf("error operator size\n");
            exit(-1);
        }   
        (this->size)=(other.size);
        for (long long i = 0; i < (this->size); i++)
        {
            (this->integer)[i]=(other.integer)[i];
            (this->decimal)[i]=(other.decimal)[i];
        }
        return (*this);
    }


    void show()
    {
        if (this->integer[0]==0)
        {
            printf("+");
            for (long long i = 0; i < this->size; i++)
            {
                printf("%c",this->integer[i]+'0');
            }
            printf(".");
            for (long long i = 0; i < this->size; i++)
            {
                printf("%c",this->decimal[i]+'0');
            }
        }
        else if (this->integer[0]==9)
        {
            printf("-");
            numbers tpp(*this);
            for (long long i = 0; i < tpp.size; i++)
            {
                tpp.decimal[i]=(9-tpp.decimal[i]);
                tpp.integer[i]=(9-tpp.integer[i]);
            }


                int cc=1;
                for (long long i = (tpp.size)-1; i >=0; i--)
                {
                    char ttmmpp=(tpp.decimal[i]+cc);
                    tpp.decimal[i]=ttmmpp%10;
                    cc=ttmmpp/10;
                }
                for (long long i = (tpp.size)-1; i >=0; i--)
                {
                    char ttmmpp=(tpp.integer[i]+cc);
                    tpp.integer[i]=ttmmpp%10;
                    cc=ttmmpp/10;
                }
                for (long long i = 0; i < tpp.size; i++)
                {
                    printf("%c", tpp.integer[i]+'0');
                }
                printf(".");
                for (long long i = 0; i < tpp.size; i++)
                {
                    printf("%c", tpp.decimal[i]+'0');
                }
                
            
        }
        
        
    }


    friend numbers operator+(const numbers &first,const numbers &second)
    {
        int c=0;
        numbers third(first.size);
        for (long long i = (first.size)-1; i >=0; i--)
        {
            char ttmmpp=(first.decimal[i]+second.decimal[i]+c);
            third.decimal[i]=ttmmpp%10;
            c=ttmmpp/10;
        }
        for (long long i = (first.size)-1; i >=0; i--)
        {
            char ttmmpp=(first.integer[i]+second.integer[i]+c);
            third.integer[i]=ttmmpp%10;
            c=ttmmpp/10;
        }
        return third;
    }


    friend numbers operator-(const numbers &first,const numbers &second)
    {
        numbers tpp(second);
        for (long long i = 0; i < tpp.size; i++)
        {
            tpp.decimal[i]=(9-tpp.decimal[i]);
            tpp.integer[i]=(9-tpp.integer[i]);
        }
        int cc=1;
        for (long long i = (tpp.size)-1; i >=0; i--)
        {
            char ttmmpp=(tpp.decimal[i]+cc);
            tpp.decimal[i]=ttmmpp%10;
            cc=ttmmpp/10;
        }
        for (long long i = (tpp.size)-1; i >=0; i--)
        {
            char ttmmpp=(tpp.integer[i]+cc);
            tpp.integer[i]=ttmmpp%10;
            cc=ttmmpp/10;
        }
        return first+tpp; 
    }


    friend numbers operator*(const numbers &first,const numbers &second)
    {
        char* one=(char*)malloc(4*first.size);
        char* two=(char*)malloc(4*second.size);

        for (int i = 0; i < 2*first.size; i++)
        {
            one[i]=first.integer[0];
            two[i]=second.integer[0];
        }
        for (int i = 0; i < first.size; i++)
        {
            one[i+2*first.size]=first.integer[i];
            two[i+2*second.size]=second.integer[i];
            one[i+3*first.size]=first.decimal[i];
            two[i+3*second.size]=second.decimal[i];
        }

 
        char* three=(char*)malloc(4*second.size);
        memset(three,0,4*first.size);
        int index=0;
        for (long long i = 4*(first.size)-1; i>=0; i--)
        {
            
            char tmp=two[i];
            char cccc=0;
            for (long long j = 4*(first.size)-1; j>=0; j--)
            {
                if ((j-index)<0)
                {
                   break;
                }  
                char ttmmpp=(three[j-index]+tmp*one[j]+cccc);
                three[j-index]=(ttmmpp%10);
                cccc=ttmmpp/10;
            }
            index++;
        }
    //////////////////////////////////////core *
        numbers ret(first.size);   
            for (long long i = 0; i <first.size; i++)
            {
                ret.decimal[i]=three[2*(first.size)+i];
            }
            for (long long i = first.size-1; i >= 0; i--)
            {
                ret.integer[i]=three[(first.size)+i];
            }
       
       //free(one);
        //free(two);
        //free(three);
        return ret;
    }


    friend numbers operator/(const numbers &first,const numbers &second)
    {
        numbers tpp(first);
        numbers tpp2(second);
        if (first.integer[0]==9)
        {
            
            for (long long i = 0; i < tpp.size; i++)
            {
                tpp.decimal[i]=(9-tpp.decimal[i]);
                tpp.integer[i]=(9-tpp.integer[i]);
            }
            int cc=1;
            for (long long i = (tpp.size)-1; i >=0; i--)
            {
                char ttmmpp=(tpp.decimal[i]+cc);
                tpp.decimal[i]=ttmmpp%10;
                cc=ttmmpp/10;
            }
            for (long long i = (tpp.size)-1; i >=0; i--)
            {
                char ttmmpp=(tpp.integer[i]+cc);
                tpp.integer[i]=ttmmpp%10;
                cc=ttmmpp/10;
            }
        }

        if (second.integer[0]==9)
        {
           
            for (long long i = 0; i < tpp2.size; i++)
            {
                tpp2.decimal[i]=(9-tpp2.decimal[i]);
                tpp2.integer[i]=(9-tpp2.integer[i]);
            }
            int cc=1;
            for (long long i = (tpp2.size)-1; i >=0; i--)
            {
                char ttmmpp=(tpp2.decimal[i]+cc);
                tpp2.decimal[i]=ttmmpp%10;
                cc=ttmmpp/10;
            }
            for (long long i = (tpp2.size)-1; i >=0; i--)
            {
                char ttmmpp=(tpp2.integer[i]+cc);
                tpp2.integer[i]=ttmmpp%10;
                cc=ttmmpp/10;
            }
        }


        char* one=(char*)malloc(4*first.size);
        char* two=(char*)malloc(4*second.size);
        for (long long i = 0; i <first.size; i++)
        {
            one[i]=tpp.integer[i];
            one[i+tpp.size]=tpp.decimal[i];
            one[i+2*tpp.size]=0;
            one[i+3*tpp.size]=0;
            two[i]=tpp2.integer[i];
            two[i+tpp2.size]=tpp2.decimal[i];
            two[i+2*tpp2.size]=0;
            two[i+3*tpp2.size]=0;
        }
    
        int point3=0;

        int times=4*first.size;
        char* result=(char*)malloc(4*first.size);
        int r_h=0;
        long long index=0;
        while(times--)
        {
            for(int i=0 ;i<=10;i++)
            {
         
                int bolo=compare(two,i,2*second.size,one,index);
                if(bolo==1)
                {
                       
                    result[r_h]=(i-1);
                    r_h++;
                    refresh(one,two,2*second.size,i-1,index);
                    index++;
                    if (index==2*second.size)
                    {
                        point3=r_h;
                    }
                    
                    break;
                }
                else if (i==10 && bolo == 0)
                {
                   printf("nununu\n");
                   exit(-1);
                }
                
            }
        }

        numbers ret(first.size);
        for (long long i = 0; i < first.size; i++)
        {
            ret.decimal[i]=result[i+point3];
        }
        long long swap=point3-1;
        for (long long i = first.size-1; i >= 0; i--)
        {
            ret.integer[i]=result[swap];
            swap--;
        }
        


        if ((first.integer[0]!=9 && second.integer[0]==9) || (first.integer[0]==9 && second.integer[0]!=9))
        {
           for (long long i = 0; i < ret.size; i++)
            {
                ret.decimal[i]=(9-ret.decimal[i]);
                ret.integer[i]=(9-ret.integer[i]);
            }
            int cc=1;
            for (long long i = (ret.size)-1; i >=0; i--)
            {
                char ttmmpp=(ret.decimal[i]+cc);
                ret.decimal[i]=ttmmpp%10;
                cc=ttmmpp/10;
            }
            for (long long i = (ret.size)-1; i >=0; i--)
            {
                char ttmmpp=(ret.integer[i]+cc);
                ret.integer[i]=ttmmpp%10;
                cc=ttmmpp/10;
            }
        }
        
         //free(one);
        // free(two);
       // free(result); 
       return ret;
    }


    friend bool operator==(const numbers &first,const numbers &second)
    {
        for (long long i = 0; i < first.size; i++)
        {
           if (first.integer[i]!=second.integer[i])
           {
                return false;
           }
           if (first.decimal[i]!=second.decimal[i])
           {
                return false;
           }
        }
        return true;
    }


    friend bool operator>(const numbers &first,const numbers &second)
    {
            numbers result=first-second;
            if (result.integer[0]==0)
            {
               return true;
            }
            else
            {
                return false;
            }
            return false;
    }


    friend bool operator<(const numbers &first,const numbers &second)
    {
            numbers result=first-second;
            if (result.integer[0]==9)
            {
               return true;
            }
            else
            {
                return false;
            }
            return false;
    }

};

numbers root(numbers n)
{
    long long size=n.size*0.5;
    char* key=(char*)malloc(size);
    
    key[0]='+';
    key[1]='0';
    key[2]='.';
    for (long long i = 3; i < size-2; i++)
    {
       key[i]='0';
    }
    
    key[size-2]='1';
    key[size-1]='\0';
    numbers bef(n.size,(char*)key);
    key[0]='-';
    numbers beh(n.size,(char*)key);
    numbers two(n.size,(char*)"+2.0");
    numbers x=n/two;
    while (1)
    {
        
        if ((((x*x)-n)>bef) || (((x*x)-n)<beh))
        {
            x=(((x*x)+n)/(two*x));
            continue;
        }
        else
        {
            break;
        }
    }
    return x;
}


int main()
 {
    numbers me(1000,(char*)"+3.0");
    numbers ret=root(me);
    ret.show();
    printf("\n");
    return 0;
}