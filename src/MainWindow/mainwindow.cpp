#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    m_pUi(new Ui::MainWindow)
{
    m_pUi->setupUi(this);
    createActions();
    createConnections();
}

MainWindow::~MainWindow()
{
    delete m_pUi;
}

void MainWindow::createActions()
{

}

void MainWindow::createConnections()
{
    connect(m_pUi->small_x_sb, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::updateFinalImageSize);
    connect(m_pUi->small_y_sb, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::updateFinalImageSize);
    connect(m_pUi->big_x_sb, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::updateFinalImageSize);
    connect(m_pUi->big_y_sb, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::updateFinalImageSize);
}

void MainWindow::browse()
{

}

void MainWindow::selectAll()
{

}

void MainWindow::deselectAll()
{

}
void MainWindow::createCollage()
{

}

void MainWindow::updateFinalImageSize()
{
    qreal small_x = m_pUi->small_x_sb->value();
    qreal small_y = m_pUi->small_y_sb->value();
    qreal big_x = m_pUi->big_x_sb->value();
    qreal big_y = m_pUi->big_y_sb->value();

    qreal coef = small_y / small_x;
    unsigned final_x = small_x * big_x * coef;
    unsigned final_y = small_y * big_y;

    if (final_x > )

    m_pUi->collage_image_size->setText(QString("(%1, %2)").arg(final_x).arg(final_y));
}
