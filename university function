#include<stdio.h>

struct stu
{
    int id;
    int age;
    int marks;
};
int main()
{
    struct stu s[10];
    int i,n;
    printf("Enter number of students");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter ID,age,marks");
        scanf("%d%d%d",&s[i].id,&s[i].age,&s[i].marks);
        if(s[i].age>=20 && (s[i].marks>=0 && s[i].marks<=100))
        {
            if(s[i].marks>=65)
                printf("\nStudent %d qualifies",i+1);
            else
                printf("Student %d is not qualified",i+1);
        }
        else
            printf("He is not eligible");
    }
return 0;
}
