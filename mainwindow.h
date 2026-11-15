#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QFileDialog>
#include <QAudioOutput>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_sliderReleased();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* TestPlayer = new QMediaPlayer;
    QAudioOutput* AudioOutput = new QAudioOutput;
    double PlayerDuration;
    void UpdatePosition();
    void UpdateDuration();
};
#endif // MAINWINDOW_H
