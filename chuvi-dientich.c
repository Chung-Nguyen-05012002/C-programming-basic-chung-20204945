#include<stdio.h>
int main ()
{
    double width,height;
    printf("nhap chieu rong , chieu dai : ");
    scanf("%lf %lf", &width, &height);
    printf("dien tich hinh tren la : %.3f \n", width * height);
    printf("chu vi cua hinh tren la : %.3f ",2*(width + height));
    return 0;
}