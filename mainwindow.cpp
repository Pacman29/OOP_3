#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f = new facade();
    pix = new QPixmap(ui->canvas->size());
    on_add_camera_btn_clicked();
    pix->fill();
    ui->camera_comboBox->setCurrentIndex(0);
    ui->canvas->setPixmap(*pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

char *MainWindow::QStringToCharArr(QString str)
{
    char* buff = (char*) malloc(sizeof(char)*str.length());
    strcpy(buff,str.toLocal8Bit().data());
    return buff;
}

void MainWindow::err_message(const char *msg)
{
    QString str(msg);
    QMessageBox::warning(this,"Error!!!",str);
}

void MainWindow::draw()
{
    order::draw dr(pix);
    if( !f->GetCommand(dr,ui->camera_comboBox->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    ui->canvas->setPixmap(*pix);
}


void MainWindow::on_load_model_btn_clicked()
{
    const char* dir = QStringToCharArr(QFileDialog::getOpenFileName(0,QObject::tr("Укажите файл с моделью"),
                                                                    QDir::currentPath(),
                                                                    QObject::tr("Все файлы (*.txt)")));
    order::load ld(dir);
    if( !f->GetCommand(ld,0))
    {
        err_message(f->get_error_message());
        return;
    }
    else
        ui->model_comboBox_2->addItem(QString::number(ui->model_comboBox_2->count())+" - "+QString(dir));
    draw();
}

void MainWindow::on_add_camera_btn_clicked()
{
    order::add_cam add_cam;
    if(!f->GetCommand(add_cam,0))
    {
        err_message(f->get_error_message());
        return;
    }
    else
        ui->camera_comboBox->addItem(QString::number(ui->camera_comboBox->count()));
    ui->canvas->setPixmap(*pix);
}

void MainWindow::on_delete_cam_btn_clicked()
{
    order::del_cam del;
    if(!f->GetCommand(del,ui->camera_comboBox->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    else
        ui->camera_comboBox->removeItem(ui->camera_comboBox->currentIndex());
    draw();
    ui->camera_comboBox->setCurrentIndex(0);
}

void MainWindow::on_yaw_btn_clicked()
{
    order::yaw_cam yaw((double)ui->yaw_spinBox->value());
    if(!f->GetCommand(yaw,ui->camera_comboBox->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
    ui->canvas->setPixmap(*pix);
}

void MainWindow::on_camera_comboBox_currentIndexChanged(int index)
{
    draw();
}

void MainWindow::on_pitch_btn_clicked()
{
    order::pitch_cam pitch((double)ui->pitch_spinBox->value());
    if(!f->GetCommand(pitch,ui->camera_comboBox->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
    ui->canvas->setPixmap(*pix);
}

void MainWindow::on_roll_btn_clicked()
{
    order::roll_cam roll((double)ui->roll_spinBox->value());
    if(!f->GetCommand(roll,ui->camera_comboBox->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
    ui->canvas->setPixmap(*pix);
}

void MainWindow::on_delete_model_btn_clicked()
{
    if(ui->model_comboBox_2->currentIndex() == 0)
        return;
    order::delete_model del;
    if(!f->GetCommand(del,ui->model_comboBox_2->currentIndex()-1))
    {
        err_message(f->get_error_message());
        return;
    }
    ui->model_comboBox_2->removeItem(ui->model_comboBox_2->currentIndex());
    draw();
}

void MainWindow::on_rotate_x_btn_clicked()
{
    order::rotate_x rot((double)ui->rotate_x_spb->value());
    if(!f->GetCommand(rot,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}

void MainWindow::on_rotate_y_btn_clicked()
{
    order::rotate_y rot((double)ui->rotate_y_spb->value());
    if(!f->GetCommand(rot,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}

void MainWindow::on_rotate_z_btn_clicked()
{
    order::rotate_z rot((double)ui->rotate_z_spb->value());
    if(!f->GetCommand(rot,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}

void MainWindow::on_move_x_btn_clicked()
{
    order::move_x m((double)ui->move_x_spb->value());
    if(!f->GetCommand(m,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}

void MainWindow::on_move_y_btn_clicked()
{
    order::move_y m((double)ui->move_y_spb->value());
    if(!f->GetCommand(m,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}

void MainWindow::on_move_z_btn_clicked()
{
    order::move_z m((double)ui->move_z_spb->value());
    if(!f->GetCommand(m,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}

void MainWindow::on_scale_btn_clicked()
{
    order::scale s((double)ui->scale_spb->value());
    if(!f->GetCommand(s,ui->model_comboBox_2->currentIndex()))
    {
        err_message(f->get_error_message());
        return;
    }
    draw();
}
