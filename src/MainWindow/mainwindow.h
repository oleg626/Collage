#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void browse();
    void selectAll();
    void deselectAll();
    void createCollage();
    void updateFinalImageSize();

private:
    void createActions();
    void createConnections();
    bool loadFile(const QString& filename);
    void setCollageImage(const QImage& image);

    QImage m_collage_image;

//    QAction* m_select_all;
//    QAction* m_deselect_all;
//    QAction* m_create_collage;
//    QAction* m_browse;

    Ui::MainWindow* m_pUi;
};

#endif // MAINWINDOW_H
