## <font color="#tomato">Разработка детектора PNG-файла</font>

Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу. 
На выходе программа должна определить, является ли данный файл PNG-изображением. 
Данная процедура не просто должна смотреть на расширение файла, 
но и произвести минимальный анализ его внутренностей, в бинарном режиме.

Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. 
Нас будут интересовать первые четыре байта. 
Первый байт всегда имеет значение −119 (число со знаком минус), 
а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные друг за другом. 
Обратите внимание, что все они в верхнем регистре.

По результатам проверки пути и внутренностей требуется сообщить пользователю 
о результате проверки в стандартный вывод.

### <font color="#tomato">Советы и рекомендации</font>

Чтобы определить расширение файла, используйте функцию substr, 
которая получает офсет и длину подстроки и возвращает её.

## <font color="#tomato">Примечание к коду:</font>

Для того чтобы сосредоточиться на сути задачи, не используются различные проверки и выбор файла. 
Всё это реализовано в [19_5_2](https://github.com/VladislavNovak/19_5_2). 
Вместо этого в массив помещается четыре пути. Три из которых заведомо неверные. 
Чтобы протестировать программу, нужно в директорию с исполняемым файлом поместить 
файл png с названием `test.co.png`.

Если это действительно png, то результат будет выглядеть:

```text
Файл ..\136.pngX не обнаружен в текущей директории
У файла ..\136.pngX должно быть расширение .png
Файл ..\test.co.png обнаружен в текущей директории и его можно открывать
У файла ..\test.co.txt должно быть расширение .png
Файл ..\test не обнаружен в текущей директории
У файла ..\test должно быть расширение .png  
```
Если же png будет ненастоящим (допустим у txt файла сменить расширение на png), то результат будет:

```text
Файл ..\136.pngX не обнаружен в текущей директории
У файла ..\136.pngX должно быть расширение .png
Файл ..\test.co.png обнаружен, но с ним какие-то проблемы (неверный заголовок)
У файла ..\test.co.txt должно быть расширение .png                            
Файл ..\test не обнаружен в текущей директории                                
У файла ..\test должно быть расширение .png   
```

---

В программе реализовано три функции. Они проверяют:

- есть ли в пути расширение png
- существует ли в принципе искомый файл на диске (в текущей директории)
- есть ли в заголовке png-файла правильные байты

Их можно было бы объединить, но подобное разделение, во-первых, более наглядно 
и, во-вторых, соответствует образовательным целям.

## <font color="#tomato">Полезные ссылки</font>

[Как получить расширение файла из строки в C ++](https://overcoder.net/q/36811/%D0%BA%D0%B0%D0%BA-%D0%BF%D0%BE%D0%BB%D1%83%D1%87%D0%B8%D1%82%D1%8C-%D1%80%D0%B0%D1%81%D1%88%D0%B8%D1%80%D0%B5%D0%BD%D0%B8%D0%B5-%D1%84%D0%B0%D0%B9%D0%BB%D0%B0-%D0%B8%D0%B7-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8-%D0%B2-c)

[std::basic_string::rfind](https://runebook.dev/ru/docs/cpp/string/basic_string/rfind)

[Преобразовать файл в двоичный код](https://hexed.it/)