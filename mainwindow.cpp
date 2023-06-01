#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(300, 150);

    m_label = new QLabel(this);
    m_label->setGeometry(10, 10, 280, 20);
    m_label->setAlignment(Qt::AlignCenter);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 40, 280, 20);
    m_slider->setRange(1, 31);
    m_slider->setValue(16);

    m_plusButton = new QPushButton("+", this);
    m_plusButton->setGeometry(200, 70, 40, 20);
    connect(m_plusButton, &QPushButton::clicked, this, &MainWindow::onPlusButtonClicked);

    m_minusButton = new QPushButton("-", this);
    m_minusButton->setGeometry(60, 70, 40, 20);
    connect(m_minusButton, &QPushButton::clicked, this, &MainWindow::onMinusButtonClicked);

    connect(m_slider, &QSlider::valueChanged, this, &MainWindow::onSliderValueChanged);
    onSliderValueChanged(16); 
}

MainWindow::~MainWindow()
{
}

void MainWindow::onPlusButtonClicked()
{
    int newValue = m_slider->value() + 1;
    if (newValue <= m_slider->maximum()) {
        m_slider->setValue(newValue);
    }
}

void MainWindow::onMinusButtonClicked()
{
    int newValue = m_slider->value() - 1;
    if (newValue >= m_slider->minimum()) {
        m_slider->setValue(newValue);
    }
}

void MainWindow::onSliderValueChanged(int value)
{
    m_label->setText(QString("Date: %1").arg(value));
}
