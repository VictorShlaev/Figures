#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeVisible(0);
    //Связь изменения типа фигуры с отображаемым меню настоект
    connect(ui->comboType, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::changeVisible);
    //событие нажатия на кнопку
    connect(ui->btnDraw, &QPushButton::clicked, this, &MainWindow::draw);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeVisible(size_t id)
{
    ui->listLog->clear();
    //выбор необходимого меню настроек, в зависимости от индекса
    std::array<QGroupBox*,4> groupBoxes {ui->groupCircle, ui->groupSquare, ui->groupRectangle, ui->groupTriangle};
    for(size_t i = 0; i<groupBoxes.size(); ++i){
        if(i == id) groupBoxes[i]->setVisible(true);
        else groupBoxes[i]->setVisible(false);
    }
}

void MainWindow::draw()
{
    ui->listLog->clear();
    int index = ui->comboType->currentIndex();
    // В зависимости от индекса, создается необходимый экземплям класса фигуры,
    // управление происходит через родительский класс
    switch (index) {
    case 0:
        formData::Circle circle;
        circle.radius = ui->dspinRadius->value()/100.;
        figure = std::make_unique<Circle>(circle);
        break;
    case 1:
        formData::Square square;
        square.side = ui->dspinSide->value()/100.;
        figure =  std::make_unique<Square>(square);
        break;
    case 2:
        formData::Rectangle rect;
        rect.width = ui->dspinW->value()/100.;
        rect.height = ui->dspinH->value()/100.;
        figure =  std::make_unique<Rect>(rect);
        break;
    case 3:
        formData::Triangle tr;
        tr.ax = ui->dspinAx->value()/100.;
        tr.ay = ui->dspinAy->value()/100.;
        tr.bx = ui->dspinBx->value()/100.;
        tr.by = ui->dspinBy->value()/100.;
        tr.cx = ui->dspinCx->value()/100.;
        tr.cy = ui->dspinCy->value()/100.;
        try{
            figure = std::make_unique<Triangle>(tr);
        }catch(std::invalid_argument& err){
            ui->listLog->addItem(err.what());
            ui->listLog->item(0)->setForeground(Qt::red);
        }
        break;
    }

    //Если условие существования треугольника не выполняется, данный блок не выполняется
    if(ui->listLog->count() == 0){
        figure->show();
        ui->listLog->addItem("Figure: "+ QString::fromStdString(figure->figureType()));
        ui->listLog->addItem("Area: "+QString::number(figure->area(), 10, 4));
        ui->listLog->addItem("Perimeter: "+ QString::number(figure->perimeter(),10,4));
    }
}



