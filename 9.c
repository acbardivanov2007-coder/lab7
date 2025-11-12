#include <stdio.h>
// Рекурсивная функция для возведения в степень
double power(double osnovanie, int stepen) 
{
    // Базовый случай - степень 0
    if (stepen == 0) {
        printf("(Любое число в степени 0 равно 1)\n");
        return 1.0;
    }
    // Если основание ноль
    if (osnovanie == 0.0) {
        if (stepen > 0) {
            return 0.0; // 0 в положительной степени = 0
        } else { // stepen < 0
            printf("Ошибка! Ноль в отрицательной степени не считается!\n");
            return 0.0;
        }
    }
    // Если степень отрицательная
    if (stepen < 0) {
        return 1.0 / power(osnovanie, -stepen); // рекурсивно для положительной степени
    }
    // Рекурсивный случай для положительной степени
    return osnovanie * power(osnovanie, stepen - 1);
}
int main()
{
    double chislo;
    int step;   
    printf("Введите число (основание): ");
    if (scanf("%lf", &chislo) != 1) {
        printf("Ошибка! Введите корректное число.\n");
        return 1;
    }
    printf("Введите степень (целое число): ");
    if (scanf("%d", &step) != 1) {
        printf("Ошибка! Введите корректную степень.\n");
        return 1;
    }
    double rezultat = power(chislo, step);    
    if (rezultat == (int)rezultat) {
        printf("%.2f ^ %d = %.0f\n", chislo, step, rezultat);
    } else {
        printf("%.2f ^ %d = %.8f\n", chislo, step, rezultat);
    }
    return 0;
}
