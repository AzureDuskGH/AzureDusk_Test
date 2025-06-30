#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 110, 100, 30));
        pushButton->setText(QCoreApplication::translate("MainWindow", "点击我", nullptr));
        MainWindow->setCentralWidget(centralwidget);
    }
};

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
