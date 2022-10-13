#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QPushButton>

class WorkerThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    WorkerThread *workerThread;
    QPushButton *pushBtn;

private slots:
    void handleResults(const QString &result);
    void pushBtnClicked();
};

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(QWidget *parent = nullptr){
        Q_UNUSED(parent);
    }

    void run() override{
        QString result = "线程开启成功";
        sleep(2);
        emit resultReady(result);
    }

signals:
    void resultReady(const QString &s);
};

#endif // MAINWINDOW_H
