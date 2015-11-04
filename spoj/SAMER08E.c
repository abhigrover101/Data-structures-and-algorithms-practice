#include<stdio.h>
int main()
{
    int c,date,month,year,bill,pdate,pmonth,pyear,pbill,count=0,i=0,daycount=0;
    int a[13];
    a[1]=31;
    a[2]=28;
    a[3]=31;
    a[4]=30;
    a[5]=31;
    a[6]=30;
    a[7]=31;
    a[8]=31;
    a[9]=30;
    a[10]=31;
    a[11]=30;
    a[12]=31;
    while(1)
    {
        date=0;month=0;year=0;pdate=0;pmonth=0;pyear=0;bill=0;pbill=0;count=0;daycount=0;
        scanf("%d",&c);
        if(c==0)
            return 0;
        for(i=0;i<c;i++)
        {

            scanf("%d%d%d%d",&date,&month,&year,&bill);
            if((year%4==0 && year%100!=0) || year%400==0)
            {
                a[2]=29;
            }
            else
                a[2]=28;

            if(i==0)
            {
                pdate=date;
                pmonth=month;
                pyear=year;
                pbill=bill;
                continue;
            }
            else if(((date-pdate)==1 && month==pmonth && year==pyear) || (year==pyear && month==pmonth+1 && pdate-date==a[pmonth]-1) || (year-pyear==1 && pmonth-month==11 && pdate-date==a[pmonth]-1))
            {
                count+=(bill-pbill);
                daycount++;
            }
            pdate=date;
            pmonth=month;
            pyear=year;
            pbill=bill;
        }
        printf("%d %d\n",daycount,count);
    }
    return 0;
}
