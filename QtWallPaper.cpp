#include "QtWallPaper.h"



QtWallPaper::QtWallPaper(QWidget *parent)
    : QWidget(parent),
    m_Tray(this,&m_WallpaperPlayer)
{
    m_WallpaperPlayer.PlayFromIniFile();
    //InitTray();
}

QtWallPaper::~QtWallPaper()
{
   
}