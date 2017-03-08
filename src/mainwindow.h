#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGame;

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QGame * m_game;

public:
    // Concstructeur avec un paramètre ayant une valeur par défaut
    // c'est à dire qu'on peut soit spécifier le paramètre par exemple:
    // QWidget * widget = new QWidget();
    // MainWindow * mw = new MainWindow(widget);
    // soit ne pas le faire et dans ce cas le paramètre du constructeur prendra la valeur par défaut (0 dans ce cas)
    // MainWindow * mw = new MainWindow(); // est équivalent à: MainWindow * mw = new MainWindow(0);
    MainWindow(QWidget * parent = 0);

protected slots:
    // Les slots ne sont pas normalement appelés directement par l'utilisateur mais activés par des signaux
    // Ils sont donc protégés ou privés

    // Slot gérant le signal d'un bouton pressé
    void keyPressEvent(QKeyEvent * e);
};

#endif // MAINWINDOW_H
