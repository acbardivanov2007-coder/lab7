#include <stdio.h>
// Функция для перевода числа в другую систему счисления
void to_base_n(int chislo, int osnovanie)
{
    // Проверяем основание
    if (osnovanie < 2 || osnovanie > 10) {
        printf("Ошибка! Основание должно быть от 2 до 10\n");
        return;
    }
    // Если число 0 - просто выводим 0
    if (chislo == 0) {
        printf("0");
        return;
    }
    // Рекурсивно переводим число
    if (chislo >= osnovanie) {
        to_base_n(chislo / osnovanie, osnovanie);
    }   
    // Выводим остаток
    printf("%d", chislo % osnovanie);
}
int main()
{
    int chislo, osnovanie;        
    // Ввод числа
    printf("Введите число (десятичное): ");
    scanf("%d", &chislo);    
    // Ввод основания системы
    printf("Введите основание системы (2-10): ");
    scanf("%d", &osnovanie);
    printf("Число %d в %d-чной системе: ", chislo, osnovanie);
    // Обрабатываем отрицательные числа
    if (chislo < 0) {
        printf("-");
        chislo = -chislo;  // Делаем число положительным для функции
    }
    // вызов функции
    to_base_n(chislo, osnovanie);
    printf("\n");
    printf("Программа завершена.\n"); 
    return 0;
}
