## Исследование Хэш-Функций

### Целые числа 
- Остаток от деления
- ![collisions_remainder](https://github.com/avarxx/Lab2024/assets/142540980/b461b5c1-17c8-4ac4-9740-d31e0965516d)
- Битовое представление
- ![collisions_bit](https://github.com/avarxx/Lab2024/assets/142540980/4b4de910-b8f1-4da7-bbb8-35c661c88320)
- Метод умножения с константой
- ![collisions_multiplication](https://github.com/avarxx/Lab2024/assets/142540980/1366609c-8896-44e3-b40d-b79e7ba44be3)

- Лучшей из этих хеш-функций оказалась Метод умножения

### Строки
- CRC32
![collisionsCrc32](https://github.com/avarxx/Lab2024/assets/142540980/ad0b100f-4556-4f60-959d-594115763639)
- длина строки
![collisionsLength](https://github.com/avarxx/Lab2024/assets/142540980/d37da44c-d37e-47f0-b6a4-e1a2ab9fc0aa)
- Полиномиальный
![collisionsPolynomial](https://github.com/avarxx/Lab2024/assets/142540980/400c0e0d-e4d8-4524-8779-81fea4352f67)
- Сумма букв
![collisionsSum](https://github.com/avarxx/Lab2024/assets/142540980/5ccd52f0-8e69-4900-9df6-b5dd635df4bc)
- Лучшей из этих хеш-функций оказалась Crc32


### Числа с плавающей точкой 
- Преобразование к (int) c последующим взятием битого представления инта
![collisionsToInt](https://github.com/avarxx/Lab2024/assets/142540980/ca4a50df-3822-4eeb-b11c-788f2b0c1a4b)
- Битовое представление
![collisionsBit](https://github.com/avarxx/Lab2024/assets/142540980/370c7255-1729-4d8e-935b-00a5281718dd)
- Извлечение экспоненты
![Извлечение экспоненты](https://github.com/avarxx/Lab2024/blob/main/Hash/Hash/Plot/collisionsExponent.png?raw=true "Извлечение экспоненты")
- Произведение мантиссы на экспоненту
![collisionsExponentMantissa](https://github.com/avarxx/Lab2024/assets/142540980/571e57b9-cb46-4473-97ca-8ccb27c84f61)
- Извлечение мантиссы
![collisionsMantissa](https://github.com/avarxx/Lab2024/assets/142540980/25d0005c-1899-4366-9101-769c1ca4cd8c)

Лучшей из этих хеш-функций оказалась Битовое представление
