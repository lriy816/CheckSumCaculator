//
// Created by lriy on 3/6/23.
//

#ifndef QTDEMO01_WINDOW_H
#define QTDEMO01_WINDOW_H
#include <QMainWindow>

namespace Ui
{
    class AppWindow;
}
class window : public QMainWindow
{
    Q_OBJECT
public:
    window(QWidget *parent = nullptr);
    ~window();
public slots:
    void on_clearButton_clicked();
    void on_beginButton_clicked();

private:
    Ui::AppWindow *ui;
    friend class ComputeIP;
};
#endif //QTDEMO01_WINDOW_H
