#pragma once
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // 添加析构函数声明

public slots:
    virtual void dummySlot() {} // 添加虚槽，确保moc生成
protected:
    void paintEvent(QPaintEvent *event) override;
};
