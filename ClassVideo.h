#pragma once

#include <QWidget.h>
#include <QAudioOutput.h>
#include <QMediaPlayer.h>
#include <QVideoWidget.h>

#include "ClassLog.h"

class ClassVideo
{

public:
	ClassVideo();
	~ClassVideo();

	void Play();
	void Play(QUrl);

	void PlayFromIniFile();

	void Pause();
	void UnPause();

	void SoundTurnOn();
	void SoundTurnOff();

	bool isPlayingVideo();
	bool isPlayingSound();

	void setVideoSource(QUrl);
	QUrl getVideoSource();

	QMediaPlayer* getMedia();
	QAudioOutput* getAudioOut();
	QVideoWidget* getVideoOut();

private:
	QUrl StdStringToQUrl(std::string);
	std::string QUrlToStdString(QUrl);

	QVideoWidget* m_VideoOut;
	QAudioOutput* m_SoundOut;
	QMediaPlayer* m_Player;

	ClassLog   m_Log;
};

