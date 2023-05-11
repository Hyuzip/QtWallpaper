#pragma once
#include <QWidget>

#include "ClassTray.h"
#include "ClassVideo.h"



class QtWallPaper : public QWidget
{
    Q_OBJECT

public:
    QtWallPaper(QWidget *parent = nullptr);
    ~QtWallPaper();

private:
    ClassTray m_Tray;
    ClassVideo m_WallpaperPlayer;
};
