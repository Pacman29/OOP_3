#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <cstring>

#include "facade/facade.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    char* QStringToCharArr(QString str);
    void err_message(const char* msg);
    void draw();

private slots:

    void on_load_model_btn_clicked();

    void on_add_camera_btn_clicked();

    void on_delete_cam_btn_clicked();

    void on_yaw_btn_clicked();

    void on_camera_comboBox_currentIndexChanged(int index);

    void on_pitch_btn_clicked();

    void on_roll_btn_clicked();

    void on_delete_model_btn_clicked();

    void on_rotate_x_btn_clicked();

    void on_rotate_y_btn_clicked();

    void on_rotate_z_btn_clicked();

    void on_move_x_btn_clicked();

    void on_move_y_btn_clicked();

    void on_move_z_btn_clicked();

    void on_scale_btn_clicked();

private:
    Ui::MainWindow *ui;
    facade* f;
    QPixmap *pix;
};

#endif // MAINWINDOW_H
