#include <stdio.h>
// Константы для тарифных ставок
#define RATE_A 8.75
#define RATE_B 9.33
#define RATE_C 10.00
#define RATE_D 11.20
// Константы для налогов
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25
#define TAX_LIMIT1 300.0
#define TAX_LIMIT2 150.0
int main()
{
    char bukva;
    float chasy, stavka;
    float zarplata, nalogi, chistaya;
    float sverhyroch_chasy, sverhyroch_oplata;
    while (1) {
        // Выводим меню с буквами
        printf("Выберите тарифную ставку:\n");
        printf("a) $%.2f/час\n", RATE_A);
        printf("b) $%.2f/час\n", RATE_B);
        printf("c) $%.2f/час\n", RATE_C);
        printf("d) $%.2f/час\n", RATE_D);
        printf("q) Выход из программы\n");
        printf("Ваша буква: ");
        // Читаем один символ
        scanf(" %c", &bukva);  // пробел перед %c чтобы пропустить перевод строки
        // Выход если выбрали q
        if (bukva == 'q' || bukva == 'Q') {
            printf("Выход из программы...\n");
            break;
        }
        // Проверяем правильность выбора
        if (bukva != 'a' && bukva != 'A' && 
            bukva != 'b' && bukva != 'B' &&
            bukva != 'c' && bukva != 'C' &&
            bukva != 'd' && bukva != 'D') {
            printf("Ошибка! Выберите a, b, c, d или q!\n\n");
            continue;
        }
        // Устанавливаем тарифную ставку
        switch (bukva) {
            case 'a':
            case 'A': stavka = RATE_A; break;
            case 'b':
            case 'B': stavka = RATE_B; break;
            case 'c':
            case 'C': stavka = RATE_C; break;
            case 'd':
            case 'D': stavka = RATE_D; break;
        }
        printf("Введите количество отработанных часов: ");
        scanf("%f", &chasy);
        // Расчет зарплаты
        if (chasy <= 40) {
            zarplata = chasy * stavka;
            sverhyroch_chasy = 0;
            sverhyroch_oplata = 0;
        } else {
            zarplata = 40 * stavka;  // первые 40 часов
            sverhyroch_chasy = chasy - 40;
            sverhyroch_oplata = sverhyroch_chasy * stavka * 1.5;  // сверхурочные ×1.5
            zarplata += sverhyroch_oplata;
        }
        // Расчет налогов
        nalogi = 0.0;
        if (zarplata <= TAX_LIMIT1) {
            nalogi = zarplata * TAX_RATE1;
        } else if (zarplata <= TAX_LIMIT1 + TAX_LIMIT2) {
            nalogi = TAX_LIMIT1 * TAX_RATE1 + 
                  (zarplata - TAX_LIMIT1) * TAX_RATE2;
        } else {
            nalogi = TAX_LIMIT1 * TAX_RATE1 + 
                  TAX_LIMIT2 * TAX_RATE2 + 
                  (zarplata - TAX_LIMIT1 - TAX_LIMIT2) * TAX_RATE3;
        }
        // Чистая зарплата
        chistaya = zarplata - nalogi;
        // Вывод результатов
        printf("результаты расчета\n");
        printf("Тарифная ставка: $%.2f/час\n", stavka);
        printf("Отработано часов: %.1f\n", chasy);
        if (sverhyroch_chasy > 0) {
            printf("Сверхурочные часы: %.1f (доплата: $%.2f)\n", 
                   sverhyroch_chasy, sverhyroch_oplata);
        }
        printf("Общая зарплата: $%.2f\n", zarplata);
        printf("Налоги: $%.2f\n", nalogi);
        printf("Чистая зарплата: $%.2f\n", chistaya);
        printf("----------------------------\n\n");
    }
    printf("Программа завершена. До свидания!\n");
    return 0;
}
