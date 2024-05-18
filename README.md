## Исследование Хэш-Функций

### Целые числа 
- Остаток от деления. 
Хеш-функция может не обеспечивать хорошое распределение, определенные шаблоны в ключах могут привести к кластеризации, что приведет к увеличению  коллизий. Данная хеш - функция хорошо работает для данных небольшого размера, для больших данных данная хеш функция не будет эфективной из за кластеризации
![Остаток от делание](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot//collisions_remainder.png)

- Битовое представление.
Битовые операции работаю быстро поэтому данная хеш функция эфективна по времени. Но происходит класеризация
![Битовое представление](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisions_bit.png)

- Метод умножения с константой
хеш-функция заключается в операции умножения `key * 2654435769`. константа получанная Кнутом `2654435769`. распределение зависит от выбора константы, можно выбрать такое значение которое для определенного набора данных будет выдавать наилучшую коллизию, данная константа равномерно распределяет по таблице
![Метод умножения с константой](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisions_multiplication.png)

### Вывод для целых чисел
Лучшей из этих хеш-функций оказалась хеш функция реализованная с помощью метода умножения на константу.


### Строки
- CRC32. 
CRC32 это алгоритм который генерирует 32-битную контрольную сумму, эффективен и может обеспечить хорошее распределение хеш-значений,возможна увеличение коллизии если данные содержат много одинаковых шаблонов.
[CRC32](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Hash/Plot/collisionsCrc32.png)
- Длина строки
Данная хеш функции определяет длинну строки имеет плохое распределение при ограниченной длинне строк, для данных тестов имеет плохую коллизию так как длинна строки ограничена от 5 до 20
[длина строки](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsLenght.png)
- Полиномиальныая
Для каждого символа строки, его ASCII-код используется для модификации текущего значения хеша. Выражение (hash << 5) выполняет сдвиг битов хеша влево на 5 позиций, а затем к результату прибавляется ASCII-код текущего символа. эта хеш-функция обычно дает хорошее распределение значений.
[Полиномиальная](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsPolynomial.png)
- Сумма букв
Хеш функция считает сумму ASCII, при относительно одининаковых строках или при совпадении суммы ASCII хеши разных строк будут одинковыми что вызывает кластеризацию 
[Сумма букв](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsSum.png)

### Вывод для строк 
- Лучшее распределение дает CRC32, но не сильно лучше чем Полиномиальная хеш функция для которой не трребует таблицу CRC32

### Числа с плавающей точкой 
- Преобразование к (int) c последующим взятием битого представления инта
Преобразование float в int может привести к потере точности и кластеризации хеш-значений, особенно для наборов данных с широким диапазоном значений с плавающей запятой
[Преобразование к (int) c последующим взятием битого представления инта](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsToInt.png)
- Битовое представление
если два разных значения float близки друг к другу в диапазоне значений с плавающей точкой, и их битовые представления очень похожи, то они окажутся в одном и том же диапазоне значений unsigned int, что приводит к коллизии 
[Битовое представление](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsBit.png)
- Извлечение экспоненты
извлечение экспоненты для хэширования дало очень плохое распределение, из за (скорее всего) ограниченного размера экспоненты числа с плавающей точкой, которая занимает всего 8 бит и ограничения чисел от [-10, 10]. 
[Извлечение экспоненты](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsExponent.png)
- Произведение мантиссы на экспоненту
Различные числа с плавающей запятой могут иметь одинаковый хеш, если их значения произведения достаточно близки после взятия модуля.
[Произведение мантиссы на экспоненту](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsExponentMantissa.png)
- Извлечение мантиссы
Поскольку хеш вычисляется только на основе мантиссы числа с плавающей запятой, два числа с разными экспонентами, но близкими мантиссами, могут иметь одинаковый хеш, что приводит к коллизии, так же взятие `%tableSize`
[Извлечение мантиссы](https://github.com/avarxx/Lab2024/tree/Hash/Hash/Plot/collisionsMantissa.png)

### Вывод для строк 
- Лучшее распределение дает Битовое представление и Извлечение мантиссы, но на больших данных лучше покажет себя хеш функция  которая  использует битовое представление 