# для студентов которые возьмут этот проект

данные хранятся в csv
можно добавлять записи
редактировать
искать
фильтровать
удаления нет

## что нужно установить
- cmake (версии 3.5 и выше)
- qt5
- компилятор c++17

## как склонировать репозиторий
1) ```bash
   git clone https://github.com/m1nazuk1/order-accounting.git
2) ```bash
   cd order-accounting

## как собрать В ТЕРМИНАЛЕ
1) ```bash
    cd /путь/к/проекту
2) ```bash
    mkdir -p build
3) ```bash
    cd build
4) ```bash
    cmake .. -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/qt@5
5) ```bash
    make
6) ```bash
    ./OrdersApp

<sub>/opt/homebrew/opt/qt@5 - (подставь свой путь к qt5)</sub>

## как собрать в clion
1) открыть проект в clion
2) в настройках cmake добавить
3) ```bash
   -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/qt@5
<sub>(подставь свой путь к qt5)<br>P.S это нужно писать в Settings → Build, Execution, Deployment → CMake в поле CMake Options</sub><br>

при первом запуске создается или подгружается orders.csv <br>
<sub>меню на macos отображается в верхней системной панели</sub><br>
<sub>на windows меню отображается обычно прямо в самом окне приложения сверху, под заголовком окна, но я хз честно как оно там плавать будет </sub><br>
# вот такие пироги
