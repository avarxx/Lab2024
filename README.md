## Исследование Хэш-Функций

### Целые числа 
- Остаток от деления
![Остаток от делания](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisions_remainder.png?raw=true "Остаток от делания")
- Битовое представление
![Битовое представление](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisions_bit.png?raw=true "Битовое представление")
- Метод умножения с константой
![Метод умножения с константой](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisions_multiplication.png?raw=true "Метод умножения с константой")

- Лучшей из этих хеш-функций оказалась Метод умножения

### Строки
- CRC32
![CRC32](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsCrc32.png?raw=true "CRC32")
- длина строки
![длина строки](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsLenght.png?raw=true "длина строки")
- Полиномиальный
![Полиномиальный](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsPolynomial.png?raw=true "Полиномиальный")
- Сумма букв
![Сумма букв](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsSum.png?raw=true "Сумма букв")
- Лучшей из этих хеш-функций оказалась Crc32


### Числа с плавающей точкой 
- Преобразование к (int) c последующим взятием битого представления инта
![Преобразование к (int) c последующим взятием битого представления инта](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsToInt.png?raw=true "Преобразование к (int)")
- Битовое представление
![Битовое представление](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsBit.png?raw=true "Битовое представление")
- Извлечение экспоненты
![Извлечение экспоненты](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsExponent.png?raw=true "Извлечение экспоненты")
- Произведение мантиссы на экспоненту
![Произведение мантиссы на экспоненту](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsExponentMantissa.png?raw=true "Произведение мантиссы на экспоненту")
- Извлечение мантиссы
![Извлечение мантиссы](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsMantissa.png?raw=true "Извлечение мантиссы")

Лучшей из этих хеш-функций оказалась Битовое представление
