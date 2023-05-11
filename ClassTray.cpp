#include "ClassTray.h"




ClassTray::ClassTray(QWidget* Window, ClassVideo* Video):
    m_Menu(new QMenu(Window)),
    m_Tray(new QSystemTrayIcon(Window)),
    m_Video(Video)
{
    QAction* Exit = new QAction("退出", Window);
    connect(Exit, &QAction::triggered, Window, []
        {
            exit(1);
        });

    QAction* ChooseWallpaper = new QAction("选择动态壁纸文件", Window);
    connect(ChooseWallpaper, &QAction::triggered, Window, [this,Window]{
        m_Video->Pause();

        QString TempFilePath = 
        QFileDialog::getOpenFileName(Window, "选择动态壁纸文件", m_Video->getVideoSource().toString(), "MV(*.mp4)");

        if (TempFilePath.isEmpty())
        {
            m_Video->UnPause();
             return;
        }
        m_Video->Play(TempFilePath);
    });

    QAction* SoundTurn = new QAction("声音", Window);
    connect(SoundTurn, &QAction::triggered, Window, [=]
        {
            if (m_Video->isPlayingSound())
                m_Video->SoundTurnOff();
            else
                m_Video->SoundTurnOn();
        });

    QAction* PlayingTurn = new QAction("暂停", Window);
    connect(PlayingTurn, &QAction::triggered, Window, [this]
        {
            if (m_Video->isPlayingVideo())
                m_Video->Pause();
            else
                m_Video->UnPause();
        });


    m_Menu->addAction(Exit);
    m_Menu->addAction(ChooseWallpaper);
    m_Menu->addAction(SoundTurn);
    m_Menu->addAction(PlayingTurn);

    m_Tray->setContextMenu(m_Menu);
    m_Tray->setIcon(QIcon(ICON_TRAY_PATH));
    m_Tray->show();
}