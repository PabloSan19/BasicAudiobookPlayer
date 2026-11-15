#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TestPlayer->setAudioOutput(AudioOutput);
    connect(TestPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::UpdatePosition);
    connect(TestPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::UpdateDuration);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // ui->progressBar->setValue(100);
    QString FileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\Users\\Pablo\\Music", tr("Audio (*.mp3 *.wav *.m4b)"));
    if(!FileName.isEmpty())
    {
        // ui->pushButton->hide();

        TestPlayer->setSource(FileName);
        TestPlayer->play();
    }
    QDebug(QtMsgType::QtDebugMsg) << FileName;
}

void MainWindow::UpdatePosition()
{
    double CurrentPosition = TestPlayer->position() / 1000;
    double Duration = PlayerDuration / 1000;
    double Percentage = (CurrentPosition / Duration) * 100;

    ui->progressBar->setValue(Percentage);
    if(!ui->horizontalSlider->isSliderDown())
    {
        ui->horizontalSlider->setValue(Percentage);
    }
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    double Position = ui->horizontalSlider->value();

    QDebug(QtMsgType::QtDebugMsg) << Position;
    double Duration = PlayerDuration;
    double Percent = (double) Position / 100;
    double NewPosition = Duration * Percent;
    QDebug(QtMsgType::QtDebugMsg) << "--------------";
    QDebug(QtMsgType::QtDebugMsg) << "New Duration: " << Duration;
    QDebug(QtMsgType::QtDebugMsg) << "New Percent: " << Percent;
    QDebug(QtMsgType::QtDebugMsg) << "New Position: " << NewPosition;
    QDebug(QtMsgType::QtDebugMsg) << "--------------";

    TestPlayer->setPosition(NewPosition);
}

void MainWindow::UpdateDuration()
{
    PlayerDuration = TestPlayer->duration();
}