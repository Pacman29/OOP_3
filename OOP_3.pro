#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T21:14:39
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP_3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vector/_vector.cpp \
    matrix/_matrix.cpp \
    object/visible_object.cpp \
    object/invisible_object.cpp \
    point/point.cpp \
    line/line.cpp \
    camera/camera.cpp \
    geometric_transformations/geometric_transformations.cpp \
    model/model.cpp \
    loader/loader.cpp \
    canvas/painter.cpp \
    canvas/graphical_sys.cpp \
    vector/g_vector.cpp \
    facade/facade.cpp \
    scene/scene_composit.cpp \
    point/point_transform.cpp \
    composit_object/composit_object.cpp \
    camera/base_camera_transformations.cpp

HEADERS  += mainwindow.h \
    vector/vector.h \
    vector/_vector.h \
    vector/base_vector.h \
    vector/base_error_vector.h \
    vector/error_vector.h \
    matrix/_matrix.h \
    matrix/matrix.h \
    matrix/base_matrix.h \
    matrix/error_matrix.h \
    matrix/base_error_matrix.h \
    base_error/base_error.h \
    object/base_object.h \
    object/visible_object.h \
    object/invisible_object.h \
    point/_point.h \
    point/point.h \
    point/error_point.h \
    camera/camera.h \
    line/line.h \
    geometric_transformations/geometric_transformations.h \
    model/model.h \
    model/model_error.h \
    line/line_error.h \
    model/base_model.h \
    line/base_line.h \
    loader/loader.h \
    loader/base_loader.h \
    loader/loader_error.h \
    canvas/base_painter.h \
    canvas/painter.h \
    canvas/painter_error.h \
    canvas/base_graphical_sys.h \
    canvas/graphical_sys.h \
    canvas/graphic_sys_error.h \
    vector/g_vector.h \
    camera/base_camera.h \
    camera/camera_transformations.h \
    camera/base_camera_transformations.h \
    facade/facade.h \
    facade/order.h \
    facade/base_order.h \
    scene/scene_composit.h \
    transformations/transformations.h \
    camera/camera_error.h \
    composit_object/composit_object.h \
    point/point_transform.h

FORMS    += mainwindow.ui

DISTFILES += \
    data.txt \
    UML.EAP
