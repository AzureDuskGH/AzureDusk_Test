#pragma once
#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    virtual void dummySlot() {}
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui_MainWindow ui;
};
