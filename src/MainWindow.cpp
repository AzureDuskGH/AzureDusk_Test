#include "MainWindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Qt 控件绘制示例");
    resize(400, 300);
}

MainWindow::~MainWindow() {
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::yellow);
    painter.drawRect(50, 50, 300, 200);
    painter.setPen(Qt::red);
    painter.drawText(rect(), Qt::AlignCenter, "Hello, Qt!");
}
