#include "ClassVideo.h"
#include "Desktop.h"
#include "ResourceDef.h"

ClassVideo::ClassVideo():
    m_Log(INI_LOG_PATH)
{
    m_Player   = new QMediaPlayer;
    m_VideoOut = new QVideoWidget;
    m_SoundOut = new QAudioOutput;

    m_Player->setLoops(QMediaPlayer::Loops::Infinite);
    m_Player->setVideoOutput(m_VideoOut);
    m_Player->setAudioOutput(m_SoundOut);

    //使背景透明防止白屏
    m_VideoOut->setAttribute(Qt::WA_TranslucentBackground);
    m_VideoOut->showFullScreen();
    setWindowToWallPaper((HWND)m_VideoOut->winId());

    //默认开启声音
    m_SoundOut->setMuted(false);
}


ClassVideo::~ClassVideo()
{
    delete m_VideoOut;
    delete m_SoundOut;
    delete m_Player;
}

void ClassVideo::Play()
{
    m_Player->play();   
}

void ClassVideo::Play(QUrl NewVideoPath)
{
    setVideoSource(NewVideoPath);
    Play();
}

void ClassVideo::PlayFromIniFile()
{
    std::string WallpaperPath = m_Log.getItem(WALLPAPERPATH_ITEM);
    Play(StdStringToQUrl(WallpaperPath));
}

void ClassVideo::Pause()
{
    m_Player->pause();
}

void ClassVideo::UnPause()
{
    m_Player->play();
}

void ClassVideo::SoundTurnOn()
{
    m_SoundOut->setMuted(false);
}

void ClassVideo::SoundTurnOff()
{
    m_SoundOut->setMuted(true);
}

bool ClassVideo::isPlayingVideo()
{
    return m_Player->isPlaying();
}

bool ClassVideo::isPlayingSound()
{
    return !m_SoundOut->isMuted();
}



void ClassVideo::setVideoSource(QUrl NewWallpaperPath)
{
    m_Player->setSource(NewWallpaperPath);
    m_Log.setItem(WALLPAPERPATH_ITEM, QUrlToStdString(NewWallpaperPath));
}

QUrl ClassVideo::getVideoSource()
{
    return m_Player->source();
}

QVideoWidget* ClassVideo::getVideoOut()
{
    return m_VideoOut;
}

std::string ClassVideo::QUrlToStdString(QUrl Qurl)
{
    return Qurl.toString().toStdString();
}

QUrl ClassVideo::StdStringToQUrl(std::string StdString)
{
    return QUrl::fromLocalFile(QString::fromStdString(StdString));
}

QMediaPlayer* ClassVideo::getMedia()
{
    return m_Player;
}

QAudioOutput* ClassVideo::getAudioOut()
{
    return m_SoundOut;
}
