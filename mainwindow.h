#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *m_label;
    QSlider *m_slider;
    QPushButton *m_plusButton;
    QPushButton *m_minusButton;

private slots:
    void onPlusButtonClicked();
    void onMinusButtonClicked();
    void onSliderValueChanged(int value);
};
#endif // MAINWINDOW_H
