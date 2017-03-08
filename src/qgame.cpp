#include "qgame.hpp"

#include "lkqmatrix.hpp"
#include "Position.hpp"
#include "qplayer.hpp"
#include "qobstacle.hpp"
#include "qobstacleM.hpp"
#include "qmonster.hpp"
#include "qbatata.hpp"
#include "EnumDirection.hpp"

#include<QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPalette>
#include <QColor>
#include <QFont>
#include <QTimer>
#include <QMessageBox>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

QGame::QGame()
{   
    QLabel * label = 0;
    QColor color = QColor(Qt::black);
    QPalette palette = QPalette(color);
    QFont font = QFont("verdana", 14, QFont::Bold, false);

    QVBoxLayout * layout_vbox = new QVBoxLayout();
    QHBoxLayout * layout_hbox = new QHBoxLayout();
    QWidget * widget_layout_hbox = new QWidget();

    label = new QLabel("steps:");
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout_hbox->addWidget(label);

    this->m_lcdNumber_steps = new QLCDNumber(5);
    this->m_lcdNumber_steps->setPalette(palette);
    this->m_lcdNumber_steps->setFont(font);
    layout_hbox->addWidget(this->m_lcdNumber_steps);

    label = new QLabel("batatas:");
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout_hbox->addWidget(label);

    this->m_lcdNumber_batatas = new QLCDNumber(5);
    this->m_lcdNumber_batatas->setPalette(palette);
    this->m_lcdNumber_batatas->setFont(font);
    layout_hbox->addWidget(this->m_lcdNumber_batatas);

    label = new QLabel("time:");
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout_hbox->addWidget(label);

    this->m_lcdNumber_seconds = new QLCDNumber(5);
    this->m_lcdNumber_seconds->setPalette(palette);
    this->m_lcdNumber_seconds->setFont(font);
    layout_hbox->addWidget(this->m_lcdNumber_seconds);

    // On définie QGame en tant que parent de timer
    // c'est à dire que QTimer sera détruit automatiquement quand QGame est détruit
    QTimer * timer = new QTimer(this);

    // Un QTimer possède un signal timeout qui est émis après qu'un nombre X de secondes est écoulé
    // ce nombre est définie par la méthode timer->start(X)
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer_timeout()));

    // Le timer va émettre un signal timeout après chaque 1000ms = 1seconde
    timer->start(1000);

    widget_layout_hbox->setLayout(layout_hbox);
    this->m_matrix = new LKQMatrix();
    this->m_matrix->setMinimumSize(100 * COLS, 100 * COLS);
    //this->m_matrix->setMaximumSize(100 * COLS, 100 * COLS);

    layout_vbox->addWidget(widget_layout_hbox, 0, Qt::AlignCenter);
    layout_vbox->addWidget(this->m_matrix, 1, Qt::AlignCenter);

    this->setLayout(layout_vbox);

    this->m_is_destroyed = false;
}

QGame::~QGame()
{
    this->m_is_destroyed = true;
}

Matrix * QGame::create_matrix()
{
    return this->m_matrix;
}

Batata * QGame::create_batata()
{
    QBatata * qbatata = new QBatata();

    // On conncete le signal au slot qui le gère grâce à la fonction statique connect de QObject
    // Une méthode statique est appellée directement à partir du nom de la classe.
    // on n'a pas donc besoin de créer un objet de type QObject pour appeler la méthode statique connect
    // le premier paramètre est l'objet emetteur du signal
    // Le deuxième paramètre est le signal, il doit correspondre à une méthode dans l'objet emetteur
    // Le signal 'signal_qbatata_destroyed' est une méthode de la classe QBatata donc c'est bon
    // Le troisième paramètre est l'objet handler dans ce cas ca sera le QGame (cet objet donc this)
    // Le quatrième paramètre doit être un slot (une méthode) appartenant à l'objet handler
    // La méthode slot_batata_destroyed est définie dans la classe QGame donc c'est bon
    QObject::connect
    (qbatata, SIGNAL(signal_qbatata_destroyed()), this, SLOT(slot_batata_destroyed()));

    int batatas_count = this->m_lcdNumber_batatas->intValue();

    this->m_lcdNumber_batatas->display(batatas_count + 1);

    return qbatata;
}

Obstacle * QGame::create_obstacle()
{
    return new QObstacle();
}

ObstacleM * QGame::create_obstacleM(Position * p_pos, Matrix * p_mat)
{
    return new QObstacleM(p_pos, p_mat);
}

Player * QGame::create_player(Position * p_pos, Matrix * p_mat)
{
    QPlayer * qplayer = new QPlayer(p_pos, p_mat);

    QObject::connect(qplayer, SIGNAL(signal_player_moved()), this, SLOT(slot_player_moved()));

    return qplayer;
}

Monster * QGame::create_monster(Position * p_pos, Matrix * p_mat)
{
    return new QMonster(p_pos, p_mat);
}

void QGame::show()
{
    this->QWidget::show();
}

void QGame::win()
{
    QMessageBox* box = new QMessageBox();

    box->setWindowTitle(QString("Win"));
    box->setText("Bravooo !!");
    box->show();
}

void QGame::start()
{
    this->place_objects();
}

void QGame::slot_batata_destroyed()
{
    if(this->m_is_destroyed == false)
    {
        int batatas_count = this->m_lcdNumber_batatas->intValue() - 1;

        this->m_lcdNumber_batatas->display(batatas_count);

        if(batatas_count == 0)
        {
            this->win();
        }
    }
}

void QGame::slot_player_moved()
{
    int steps_count = this->m_lcdNumber_steps->intValue() + 1;

    this->m_lcdNumber_steps->display(steps_count);
}

void QGame::slot_timer_timeout()
{
    int seconds = this->m_lcdNumber_seconds->intValue() + 1;

    this->m_lcdNumber_seconds->display(seconds);
}
