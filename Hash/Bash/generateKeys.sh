#!/bin/bash

gcc generateData.c -o generateData

if [ $? -ne 0 ]; then
    echo "Ошибка при компиляции generateData.c"
    exit 1
fi

./generateData >> unsigned_int_keys.txt
./generateData >> float_keys.txt
./generateData >> string_keys.txt

if [ $? -ne 0 ]; then
    echo "Ошибка при выполнении generateData"
    exit 1
fi

echo "Данные успешно сгенерированы и записаны в файлы."
