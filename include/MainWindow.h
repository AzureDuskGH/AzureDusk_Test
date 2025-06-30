#pragma once

#include <QMainWindow>

// 优先包含 build 目录下自动生成的 ui_MainWindow.h
#if __has_include("../build/ui_MainWindow.h")
#include "../build/ui_MainWindow.h"
#elif __has_include("../build/device_manager_autogen/include/ui_MainWindow.h")
#include "../build/device_manager_autogen/include/ui_MainWindow.h"
#else
#include "ui_MainWindow.h"
#endif

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
