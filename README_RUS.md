# Basic CI/CD

Разработка простого **CI/CD** для проекта *SimpleBashUtils*. Сборка, тестирование, развертывание.

### Part 1. Настройка **gitlab-runner**

##### Поднять виртуальную машину *Ubuntu Server 22.04 LTS*.

##### Скачать и установить на виртуальную машину **gitlab-runner**.

##### Запустить **gitlab-runner** и зарегистрировать его для использования в текущем проекте.

### Part 2. Сборка

#### Написать этап для **CI** по сборке приложений из проекта Bash Utils.

##### В файле _gitlab-ci.yml_ добавить этап запуска сборки через мейк файл из проекта Bash Utils.

##### Файлы, полученные после сборки (артефакты), сохранить в произвольную директорию со сроком хранения 30 дней.

### Part 3. Тест кодстайла

#### Написать этап для **CI**, который запускает скрипт кодстайла.

##### В пайплайне отобразить вывод утилиты *clang-format*.

### Part 4. Интеграционные тесты

#### Написать этап для **CI**, который запускает интеграционные тесты из того же проекта.

##### Запустить этот этап автоматически только при условии, если сборка и тест кодстайла прошли успешно.

##### В пайплайне отобразить вывод, что интеграционные тесты успешно прошли / провалились.

### Part 5. Этап деплоя

##### Поднять вторую виртуальную машину *Ubuntu Server 22.04 LTS*.

#### Написать этап для **CD**, который «разворачивает» проект на другой виртуальной машине.

##### Запустить этот этап вручную при условии, что все предыдущие этапы прошли успешно.

##### Написать bash-скрипт, который при помощи **ssh** и **scp** копирует файлы, полученные после сборки (артефакты), в директорию */usr/local/bin* второй виртуальной машины.

##### В файле _gitlab-ci.yml_ добавить этап запуска написанного скрипта.

### Part 6. Уведомления

##### Настроить уведомления о успешном/неуспешном выполнении пайплайна через бота с именем «hactarca CI/CD» в *Telegram*.

- Текст уведомления должен содержать информацию об успешности прохождения как этапа **CI**, так и этапа **CD**.

