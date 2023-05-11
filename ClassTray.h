#pragma once
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu.h>
#include <QFileDialog>

#include "ResourceDef.h"
#include "ClassVideo.h"

class ClassTray : public QObject
{
	Q_OBJECT

public:
	ClassTray(QWidget*, ClassVideo*);

private:
	QMenu*           m_Menu;
	QSystemTrayIcon* m_Tray;
	ClassVideo*		 m_Video;
};

