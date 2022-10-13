#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    pushBtn = new QPushButton(this);
    workerThread = new WorkerThread(this);
    pushBtn->resize(100, 40);
    pushBtn->setText("开启线程");
    connect(workerThread, &WorkerThread::resultReady,
            this, &MainWindow::handleResults);
    connect(pushBtn, &QPushButton::clicked,
            this, &MainWindow::pushBtnClicked);
}

void MainWindow::handleResults(const QString &result)
{
    qDebug() << result << endl;
}thread_local

void MainWindow::pushBtnClicked()
{
    if(!workerThread->isRunning())
        workerThread->start();
}

MainWindow::~MainWindow()
{
    workerThread->quit();
    if(workerThread->wait(2000)){
        qDebug() << "线程已经结束" << endl;
    }
}
