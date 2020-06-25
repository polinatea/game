#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Form::Form(QWidget *parent) : game(NULL),
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

//    layout = new QVBoxLayout(this);
//    settingsLayout = new QHBoxLayout;

    /* Кнопки начала новой игры и выхода из игры */
    QPushButton* newgame = new QPushButton();
    QPushButton* exitgame = new QPushButton();


    /* Создаем растровое изображение */
    QPixmap newG(":/tusya/new2.png");
    QPixmap exG(":/tusya/exit2.png");

    /* Генерируем изображения для использования виджетом */
    QIcon newGIcon(newG);
    QIcon exGIcon(exG);

    /* Используем QIcon созданную в QPixmap */
    newgame->setIcon(newGIcon);
    exitgame->setIcon(exGIcon);

    /* Задаем размеры */
    newgame->setIconSize(QSize(304,70));
    exitgame->setIconSize(QSize(290,70));
    /* Соединяем сигнал со слотом */
    connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(exitgame, SIGNAL(clicked()), this, SLOT(exitGame()));

    /* Размещаем виджеты по горизонтали слева направо */

    settingsLayout->addWidget(newgame);
    settingsLayout->addWidget(exitgame);

    /* Устанавливаем поля вокруг макета */
    layout->setContentsMargins(2, 2, 2, 2);

    /* Добавляем макет в конец поля */
    layout->addLayout(settingsLayout);



    /* Сигнал начала игры */
    newGame();
    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;

    /* Применяем размещение */
    setLayout(layout);
}

Form::~Form()
{
    delete ui;
}

void Form::newGame()
{
    if(game) //удаляем старое поле
    {
        layout->removeWidget(game);  // удаляем виджет из макета
        delete game;
    }

    game = new Game(/*4, */this); //рисуем новое поле

    /* Добавляем виджет в компоновщик */
    layout->addWidget(game);

    /* Обновляем компоновщик */
    layout->update();

    game->hide();
    game->show();

    /* Меняем размер окна*/
    resize(sizeHint());
}

void Form::exitGame()
{
    MainWindow *f = new MainWindow();
    f->show();
    this->close();
}


