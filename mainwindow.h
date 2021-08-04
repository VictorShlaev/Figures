#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <array>
#include <QGroupBox>
#include <memory>
#include "formData.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "circle.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void changeVisible(size_t id);
    std::unique_ptr<Figure> figure;
private slots:
    void draw();
};
#endif // MAINWINDOW_H
