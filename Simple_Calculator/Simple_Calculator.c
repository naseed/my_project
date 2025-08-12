#include <stdio.h>
int main()
{
    char op;
    float a,b;
    float result = 0;
    printf("enter the number a :");
    scanf("%f", &a);

    printf("enter the opertaion (+ - * /) : ");
    scanf(" %c", &op);

    printf("enter the number b :");
    scanf("%f", &b);

    switch (op)
    {
    case '+' :
        result = a + b;
        break;
    case '-' :
        result = a - b;
        break;
    case '*' :
        result = a * b;
        break;
    case '/' :
        if (b != 0)
            result = a / b;
        else
        {
            printf("Erreur \n");
            return -1;
        }
        break;
    default:
        printf("operation invalide pls retry \n");
        break;
    }
    printf("%.2f %c %.2f = %.2f",a,op,b,result);
    return 0;   
}